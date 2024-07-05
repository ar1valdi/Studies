#include <stdio.h>
#include <crtdbg.h>
#include "queue_list_th.h"
#include "Windows.h"

#define TRUE  1
#define FALSE 0
int quit = FALSE;
volatile DWORD idToKill = (DWORD)-1;
queue** global_q_ptr = NULL;

int stopThread(HANDLE threadHandle) {
    idToKill = GetThreadId(threadHandle);
    DWORD result = WaitForSingleObject(threadHandle, 5000);
    if (result != WAIT_OBJECT_0) {
        idToKill = (DWORD)-1;
        printf("Can't close thread ID=%d: (%d)", GetThreadId(threadHandle), GetLastError());
        (void)getchar();
        return 1;
    }
    CloseHandle(threadHandle);
    idToKill = (DWORD)-1;
    return 0;
}

DWORD WINAPI ThreadFunc(void* params) {
    long long int iters = 1;
    int pow = *((int*)params);
    for (int i = 0; i < pow; i++) {
        iters *= 2;
    }
    double pi = 0.0;
    int sign = 1;
    long long int i = 0;

    for (; i < iters; i++) {
        double temp = 1.0 / (2 * i + 1);
        pi += sign * temp;
        sign = -sign;

        if (idToKill == (DWORD)GetCurrentThreadId()) {
            break;
        }
    }

    pi *= 4;

    printf("PI approximation calculated with %lld iterations\n%.15f\n", i, pi);
    if (qremove(global_q_ptr, GetCurrentThreadId()) != 0) {
        printf("Did not delete - %d", GetCurrentThreadId());
    }
    free(params);
    return 0;
}

HANDLE startNewThread(int prio, int params)
{
    int* p = (int*)malloc(sizeof(int));
    if (p == NULL) { return INVALID_HANDLE_VALUE; }
    *p = params;
    HANDLE threadHandle = CreateThread(
        NULL,
        0,
        ThreadFunc,
        (void*)p,
        0,
        0
    );

    if (threadHandle == INVALID_HANDLE_VALUE || threadHandle == NULL)
    {
        printf("CreateProcess failed (%d).\n", GetLastError());
        return INVALID_HANDLE_VALUE;
    }

    int newPrio;
    switch (prio) {
    case 1:
        newPrio = THREAD_PRIORITY_ABOVE_NORMAL;
        break;
    case 2:
        newPrio = THREAD_PRIORITY_BELOW_NORMAL;
        break;
    case 3:
        newPrio = THREAD_PRIORITY_HIGHEST;
        break;
    case 4:
        newPrio = THREAD_PRIORITY_IDLE;
        break;
    case 5:
        newPrio = THREAD_PRIORITY_LOWEST;
        break;
    case 7:
        newPrio = THREAD_PRIORITY_TIME_CRITICAL;
        break;
    default:
        newPrio = THREAD_PRIORITY_NORMAL;
        break;
    }

    if (SetThreadPriority(threadHandle, newPrio) == 0) {
        printf("Can't set priority: (%d).\n", GetLastError());
        (void)getchar();
    }

    return threadHandle;
}

void printWrongInput() {
    printf("Incorrect input. Try again\n");
    printf("Press enter to continue...\n");
    (void)getchar();
}

void printMenu() {
    printf("Program podrzedny\n");
    printf("1. Create new thread\n");
    printf("2. Delete thread\n");
    printf("3. Show all running threads\n");
    printf("4. Kill all threads and quit\n");
}

void burnBuffer() {
    while (getchar() != '\n');
}

int selectPriorityMenu() {
    while (1) {
        //system("cls");
        printf("Select priority:\n");
        printf("1. Above normal\n");
        printf("2. Below normal\n");
        printf("3. Highest\n");
        printf("4. Idle\n");
        printf("5. Lowest\n");
        printf("6. Normal\n");
        printf("7. Time critical\n");

        char c = getchar();
        if (getchar() == '\n') {
            switch (c) {
            case '1': case '2': case '3': case '4': case '5': case '6': case '7':
                return c - '0';
            default:
                printWrongInput();
            }
        }
        else {
            burnBuffer();
            printWrongInput();
        }
    }
}

void createNewThread(queue** q) {
    int prio = selectPriorityMenu();
    int param;
    //system("cls");
    printf("Select x for iterations number 2^x: ");
    (void)scanf_s("%d", &param);
    (void)getchar();
    HANDLE data = startNewThread(prio, param);

    HANDLE* h = (HANDLE*)malloc(sizeof(HANDLE));
    if (h == NULL) {
        printf("Can't add to thread list: (%d)", GetLastError());
        stopThread(data);
        return;
    }
    *h = data;
    qpush(q, h);

    //system("cls");
    printf("Thread with ID=%d created\n", GetThreadId(data));
    printf("Press enter to continue...\n");
    (void)getchar();
}

void stopChosenThread(queue** q) {
    int id;
    printf("Enter id: ");
    (void)scanf_s("%d", &id);
    (void)getchar();

    const HANDLE* h = qget(*q, id);
    if (h == NULL) {
        printf("Incorrect ID\n");
    }
    else {
        if (stopThread(*h) == 1) {
            return;
        }
        printf("Terminated process with ID=%d\n", id);
    }
    printf("Press enter to continue...\n");
    (void)getchar();
}

void showThreads(queue* q) {
    qlist(q);
    printf("Press enter to continue...\n");
    (void)getchar();
}

void closeApp(queue** q) {

    while (*q != NULL) {
       HANDLE* h = qgetat(*q, 0);
        if (stopThread(*h) == 1) {
            return;
        }
    }

    quit = TRUE;
    printf("All processes shut\n");
    printf("Press enter to continue...\n");
    (void)getchar();
}

void doAction(char c, queue** q) {
    switch (c) {
    case '1':
        createNewThread(q);
        break;
    case '2':
        stopChosenThread(q);
        break;
    case '3':
        showThreads(*q);
        break;
    case '4':
        closeApp(q);
        break;
    default:
        printWrongInput();
    }
}

int main(int argc, char* argv[])
{
    queue* q = NULL;
    global_q_ptr = &q;

    while (quit == FALSE) {
        printMenu();
        char c = getchar();
        if (getchar() == '\n') {
            doAction(c, &q);
        }
        else {
            burnBuffer();
            printWrongInput();
        }
    }

    _CrtDumpMemoryLeaks();
    return 0;
}