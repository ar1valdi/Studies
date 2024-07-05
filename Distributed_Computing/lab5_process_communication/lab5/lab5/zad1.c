// HelloWindowsDesktop.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

static TCHAR szWindowClass[] = _T("DesktopApp");
static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");
HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HBRUSH bgBrush;

HWND moveButton;
HWND paintButton;
HWND sizeButton;
HWND clearButton;
HWND consoleHnd;

int showPaint = 0;
int showMove = 0;
int showSize = 0;


void cls(HANDLE hConsole)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SMALL_RECT scrollRect;
    COORD scrollTarget;
    CHAR_INFO fill;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Scroll the rectangle of the entire buffer.
    scrollRect.Left = 0;
    scrollRect.Top = 0;
    scrollRect.Right = csbi.dwSize.X;
    scrollRect.Bottom = csbi.dwSize.Y;

    // Scroll it upwards off the top of the buffer with a magnitude of the entire height.
    scrollTarget.X = 0;
    scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

    // Fill with empty spaces with the buffer's default text attribute.
    fill.Char.UnicodeChar = TEXT(' ');
    fill.Attributes = csbi.wAttributes;

    // Do the scroll
    ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

    // Move the cursor to the top left corner too.
    csbi.dwCursorPosition.X = 0;
    csbi.dwCursorPosition.Y = 0;

    SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(0,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            0);

        return 1;
    }

    hInst = hInstance;

    HWND hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        300, 230,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    AllocConsole();
    consoleHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!consoleHnd)
    {
        MessageBox(0,
            _T("Assign console handle failed!"),
            _T("Windows Desktop Guided Tour"),
            0);

        return 1;
    }

    const int startX = 10;
    const int startY = 50;
    const int spacing = 10;
    const int height = 20;
    const int width = 100;
    bgBrush = CreateSolidBrush(RGB(150, 150, 150));

    moveButton = CreateWindow(TEXT("BUTTON"), TEXT("WM_MOVE"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
        startX, startY, width, height, hWnd, NULL, hInstance, NULL);
    sizeButton = CreateWindow(TEXT("BUTTON"), TEXT("WM_SIZE"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
        startX, startY + (height + spacing) * 1, width, height, hWnd, NULL, hInstance, NULL);
    paintButton = CreateWindow(TEXT("BUTTON"), TEXT("WM_PAINT"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
        startX, startY + (height + spacing) * 2, width, height, hWnd, NULL, hInstance, NULL);
    clearButton = CreateWindow(TEXT("BUTTON"), TEXT("Clear"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        startX, startY + (height + spacing) * 3, width, height, hWnd, NULL, hInstance, NULL);

    if (!hWnd)
    {
        MessageBox(0,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            0);

        return 1;
    }

    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DeleteObject(bgBrush);
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("Choose option:");
    DWORD written;

    switch (message)
    {
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED)
        {
            HWND h = (HWND)lParam;
            BOOL checked = SendMessage(h, BM_GETCHECK, 0, 0);

            if (h == paintButton) {
                if (checked == BST_CHECKED) {
                    showPaint = 1;
                }
                else {
                    showPaint = 0;
                }
            } 
            else if (h == moveButton) {
                if (checked == BST_CHECKED) {
                    showMove = 1;
                }
                else {
                    showMove = 0;
                }
            } 
            else if (h == sizeButton) {
                if (checked == BST_CHECKED) {
                    showSize = 1;
                }
                else {
                    showSize = 0;
                }
            }
            else if (h == clearButton) {
                cls(consoleHnd);
            }
        }
        break;
    case WM_KEYDOWN:
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        if (showPaint) {
            WriteConsoleA(consoleHnd, "WM_PAINT\n", 9, &written, NULL);
        }
        TextOut(hdc,
            10, 10,
            greeting, (int)_tcslen(greeting));

        EndPaint(hWnd, &ps);
        break;
    case WM_SIZE:
        if (showSize) {
            WriteConsoleA(consoleHnd, "WM_SIZE\n", 8, &written, NULL);
        }
        break;
    case WM_MOVE:
        if (showMove) {
            WriteConsoleA(consoleHnd, "WM_MOVE\n", 8, &written, NULL);
        }
        break;
    case WM_CLOSE:
        WriteConsoleA(consoleHnd, "WM_QUIT\n", 8, &written, NULL);
        Sleep(3000);
        FreeConsole();
        PostQuitMessage(0);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_ERASEBKGND:
    {
        RECT rcClient;
        GetClientRect(hWnd, &rcClient);
        FillRect((HDC)wParam, &rcClient, bgBrush);
        return TRUE;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}