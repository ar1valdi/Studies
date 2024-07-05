#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#pragma comment (lib, "Ws2_32.lib")
//#pragma comment (lib, "Mswsock.lib")
//#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 16
#define DEFAULT_PORT "27015"

WSADATA wsaData;
SOCKET ConnectSocket = INVALID_SOCKET;
struct addrinfo* result = NULL,
    * ptr = NULL,
    hints;
int iResult;

int quit = 0;
int wait = 0;

DWORD WINAPI reciever(LPVOID lParam) {
    char recvbuf[DEFAULT_BUFLEN];
    while(1) {
        for (int i = 0; i < DEFAULT_BUFLEN; i++) {
            recvbuf[i] = 0;
        }

        iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
        if (quit == 1) {
            return 0;
        }
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            printf("Recieved: %s\n", recvbuf);
            wait = 0;
        
            if (strcmp(recvbuf, "quit") == 0) {
                break;
            }
        }
        else if (iResult == 0) {
            printf("Connection closed\n");
            break;
        }
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            break;
        }
    }
    closesocket(ConnectSocket);
    WSACleanup();
    printf("Server closed. App will close in 3 sec");
    Sleep(3000);
    ExitProcess(0);
}

void tostring(char str[], int num)
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = 0;
}

void printMenu() {
    printf("CLIENT APP\n");
    printf("1. calculate PI using Leibniz method\n");
    printf("2. close server\n");
    printf("3. quit\n");
}

int menuCalcPI() {
    printf("Enter n for 2^n num of iterations: ");
    int iters;
    scanf_s("%d", &iters);
    (void)getchar();
    return iters;
}

int init(const char* serverName) {
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(serverName, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }
    return 0;
}

int connectToServer() {
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %d\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }
    return 0;
}

int sendToServer(char* txt, char* serverName) {
    int strLen = (int)strlen(txt) + 1;
    iResult = send(ConnectSocket, txt, strLen, 0);
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }
    return 0;
}

int __cdecl main(int argc, char** argv) {
    char serv[] = "localhost";

    char sendbuf[DEFAULT_BUFLEN];

    if (init(serv)) {
        return 1;
    }
    if (connectToServer()) {
        return 1;
    }

    CreateThread(NULL, 0, reciever, NULL, 0, NULL);
    
    do {
        if (wait == 1) {
            continue;
        }
        printMenu();
        int choice = getchar() - '0';
        (void)getchar();
        switch (choice) {
            case 1: {
                int iters = menuCalcPI();
                tostring(sendbuf, iters);
                sendToServer(sendbuf, serv);
                wait = 1;
                break;
            }
            case 2:
                strcpy_s(sendbuf, 5, "quit");
                sendToServer(sendbuf, serv);
                break;
            case 3:
                quit = 1;
                break;
            default:
                break;
        }
    } while (quit == 0);

    int iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    closesocket(ConnectSocket);
    WSACleanup();
    return 0;
}