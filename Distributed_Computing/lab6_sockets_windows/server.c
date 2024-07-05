#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 256
#define DEFAULT_PORT "27015"
#define MAX_THREADS 100

struct addrinfo* result = NULL;
struct addrinfo hints;

SOCKET MainSocket = INVALID_SOCKET;
HANDLE threads[MAX_THREADS];
SOCKET* sock[MAX_THREADS];
int run = 1;

HANDLE log_mutex;

void log_message(const char* message) {
    WaitForSingleObject(log_mutex, INFINITE);

    FILE* log_file = fopen("logfile.txt", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file\n");
        ReleaseMutex(log_mutex);
        return;
    }
    fprintf(log_file, "%s\n", message);
    fclose(log_file);
    ReleaseMutex(log_mutex);
}

int init(SOCKET* ListenSocket, WSADATA* wsaData) {
    for (int i = 0; i < MAX_THREADS; i++) {
        threads[i] = INVALID_HANDLE_VALUE;
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        sock[i] = (SOCKET*)malloc(sizeof(SOCKET));
        if (sock[i] == NULL) {
            return 1;
        }
        *sock[i] = INVALID_SOCKET;
    }

    // Initialize Winsock
    int iResult = WSAStartup(MAKEWORD(2, 2), &*wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for the server to listen for client connections.
    *ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (*ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(*ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(*ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(*ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(*ListenSocket);
        WSACleanup();
        return 1;
    }

    return 0;
}

SOCKET* handleClientAcceptance(SOCKET* ListenSocket) {
    printf("Listening...\n");
    SOCKET* newSocket = NULL;
    for (int i = 0; i < MAX_THREADS; i++) {
        if (*sock[i] == INVALID_SOCKET) {
            newSocket = sock[i];
            break;
        }
    }
    if (newSocket == NULL) {
        printf("accept failed with error: not enough memory for new socket\n");
        return NULL;
    }
    *newSocket = accept(*ListenSocket, NULL, NULL);
    if (*newSocket == INVALID_SOCKET) {
        if (WSAGetLastError() == 10004) {
            printf("socket closed\n");
        } else 
        printf("accept failed with error: %d\n", WSAGetLastError());
        return NULL;
    }
    printf("accepted new client\n");
    return newSocket;
}

DWORD WINAPI handleClientConnection(LPVOID lpParam) {
    SOCKET* client = (SOCKET*)lpParam;
    char logbuf[DEFAULT_BUFLEN];

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    char sendbuf[DEFAULT_BUFLEN];
    int buflen = DEFAULT_BUFLEN;
    int err = 0;

    int iResult = recv(*client, recvbuf, buflen, 0);
    if (iResult > 0) {
        size_t max_recvbuf_length = sizeof(logbuf) - (strlen("TH  - received: ") + 1); // +1 for null terminator
        snprintf(logbuf, sizeof(logbuf), "TH %ld - received: %.*s\n", GetCurrentThreadId(), (int)max_recvbuf_length, recvbuf);
        log_message(logbuf);
    }

    while (iResult > 0) {
        if (strcmp(recvbuf, "quit") == 0) {
            run = 0;
            break;
        }
        else {
            double pi = 0.0;
            int sign = 1;
            int denominator = 1;

            int n = atoi(recvbuf);
            double max = pow(2, n);
            double nexPerc = 0.1;
            for (double i = 0; i < max; i++) {
                pi += sign * 4.0 / denominator;
                sign = -sign;  
                denominator += 2; 

                double perc = i / max;
                if (perc >= nexPerc) { 
                    //snprintf(sendbuf, 20, "%f", pi);
                    //sendbuf[20] = 0;
                    char percbuf[21]; 
                    snprintf(percbuf, 19, "%f", perc);
                    percbuf[20] = 0;
                    size_t max_recvbuf_length = sizeof(logbuf) - (strlen("TH  - perc: , pi: \n") + 1); // +1 for null terminator
                    snprintf(logbuf, sizeof(logbuf), "TH %ld - perc: %.*s, pi: %f\n", GetCurrentThreadId(), (int)max_recvbuf_length, percbuf, pi);
                    log_message(logbuf);
                    nexPerc += 0.05;
                }

                if (run == 0) {
                    break;
                }
            }
            if (run != 0) {
                snprintf(sendbuf, 20, "%f", pi);
                sendbuf[20] = 0;

                iSendResult = send(*client, sendbuf, (int)strlen(sendbuf), 0);
                if (iSendResult == SOCKET_ERROR) {
                    printf("send failed with error: %d\n", WSAGetLastError());
                    err = 1;
                    break;
                }
                size_t max_recvbuf_length = sizeof(logbuf) - (strlen("TH  - sent: ") + 1); // +1 for null terminator
                snprintf(logbuf, sizeof(logbuf), "TH %ld - sent: %.*s\n", GetCurrentThreadId(), (int)max_recvbuf_length, sendbuf);
                log_message(logbuf);
            }
        }
        if (run == 0) {
            break;
        }

        iResult = recv(*client, recvbuf, DEFAULT_BUFLEN, 0);
        size_t max_recvbuf_length = sizeof(logbuf) - (strlen("TH  - received: ") + 1); // +1 for null terminator
        snprintf(logbuf, sizeof(logbuf), "TH %ld - received: %.*s\n", GetCurrentThreadId(), (int)max_recvbuf_length, recvbuf);
        log_message(logbuf);
    }

    if (err == 0 && run == 1) {
        if (iResult != 0) {
            sprintf(logbuf, "TH %ld - recv failed with error: %d\n", GetCurrentThreadId(), WSAGetLastError());
            log_message(logbuf);
            err = 1;
        }

        int iResult = shutdown(*client, SD_SEND);
        if (iResult == SOCKET_ERROR) {
            sprintf(logbuf, "TH %ld - recv failed with error: %d\n", GetCurrentThreadId(), WSAGetLastError());
            log_message(logbuf); 
            err = 1;
        }
    }

    if (run == 1) {
        closesocket(*client);
        *client = INVALID_SOCKET;
        for (int i = 0; i < MAX_THREADS; i++) {
            if (GetThreadId(threads[i]) == GetCurrentThreadId()) {
                threads[i] = INVALID_HANDLE_VALUE;
                break;
            }
        }

        sprintf(logbuf, "TH %ld - closed connection\n", GetCurrentThreadId());
        log_message(logbuf);
    }
    return err;
}

DWORD WINAPI closeAllSockets(LPVOID lpParam) {
    char sendbuf[] = "quit";
    while (1) {
        Sleep(100);
        if (run == 0) {
            for (int i = 0; i < MAX_THREADS; i++) {
                if (*sock[i] != INVALID_SOCKET) {
                    send(*sock[i], sendbuf, (int)strlen(sendbuf), 0);
                    closesocket(*sock[i]);
                }
            }
            closesocket(MainSocket);
            break;
        }
    }

    return 0;
}

int createClientReqHandler(SOCKET* clientSocket) {
    if (clientSocket == NULL) {
        return 1;
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        if (threads[i] == INVALID_HANDLE_VALUE) {
            threads[i] = CreateThread(NULL, 0, handleClientConnection, (LPVOID)clientSocket, 0, NULL);
            if (threads[i] == NULL) {
                fprintf(stderr, "Error creating thread %d\n", i);
                return 1;
            }
            return 0;
        }
    }
    return 1;
}

int __cdecl main(void)
{
    log_mutex = CreateMutex(NULL, FALSE, NULL);
    if (log_mutex == NULL) {
        fprintf(stderr, "Error creating mutex\n");
        return 1;
    }


    CreateThread(NULL, 0, closeAllSockets, NULL, 0, NULL);

    WSADATA wsaData;

    printf("Starting server...\n");
    if (init(&MainSocket, &wsaData) == 1) {
        return 1;
    }

    do {
        SOCKET* newSock = handleClientAcceptance(&MainSocket);
        if (newSock == NULL && run == 1) {
            continue;
        }

        if (createClientReqHandler(newSock) == 1 && run == 1) {
            char sendbuf[30];
            strcpy_s(sendbuf, 30, "can't create request handler");
            int sRes = send(*newSock, sendbuf, 30, 0);
            if (sRes == SOCKET_ERROR) {
                printf("send{can't create request handler} failed with error: %d\n", WSAGetLastError());
                continue;
            }
            free(newSock);
        }
    } while (run == 1);

    WSACleanup();
    printf("server closed");

    for (int i = 0; i < MAX_THREADS; i++) {
        free(sock[i]);
    }
    return 0;
}