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

#define BUFFER_SIZE 128
#define MY_FORMAT _T("CustomFormat")
UINT formatID;

HWND cutButton;
HWND copyButton;
HWND pasteButton;
HWND clearButton;
HWND textBox;
HWND hWnd;

void putInClipboardWithCustomFormat(LPSTR data, int len) {
    HGLOBAL hGlMem = GlobalAlloc(GHND, (DWORD)len + 1);
    if (hGlMem == 0) { return; }
    LPVOID lpGlMem = GlobalLock(hGlMem);
    if (lpGlMem == 0) { 
        GlobalUnlock(hGlMem);
        GlobalFree(hGlMem);
        return; 
    }
    memcpy(lpGlMem, data, len + 1);
    OpenClipboard(hWnd);
    EmptyClipboard();
    SetClipboardData(formatID, hGlMem);
    CloseClipboard();
}

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
    FreeConsole();
    formatID = RegisterClipboardFormat(MY_FORMAT);
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

    hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 250,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    const int startX = 10;
    const int startY = 50;
    const int spacing = 10;
    const int height = 20;
    const int width = 100;
    bgBrush = CreateSolidBrush(RGB(150, 150, 150));

    cutButton = CreateWindow(TEXT("BUTTON"), TEXT("CUT"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        startX, startY, width, height, hWnd, NULL, hInstance, NULL);
    copyButton = CreateWindow(TEXT("BUTTON"), TEXT("COPY"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        startX, startY + (height + spacing) * 1, width, height, hWnd, NULL, hInstance, NULL);
    pasteButton = CreateWindow(TEXT("BUTTON"), TEXT("PASTE"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        startX, startY + (height + spacing) * 2, width, height, hWnd, NULL, hInstance, NULL);
    clearButton = CreateWindow(TEXT("BUTTON"), TEXT("CLEAR"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        startX, startY + (height + spacing) * 3, width, height, hWnd, NULL, hInstance, NULL);
    textBox = CreateWindow(TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
            startX + spacing * 3 + width, startY, 300, 4 * height + 3 * spacing, hWnd, NULL, hInstance, NULL);

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
    TCHAR greeting[] = _T("Zadanie 2");

    switch (message)
    {
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED)
        {
            HWND h = (HWND)lParam;

            if (h == copyButton) {
                TCHAR text[BUFFER_SIZE];
                GetWindowText(textBox, text, BUFFER_SIZE);
                putInClipboardWithCustomFormat(text, BUFFER_SIZE - 1);
            }
            else if (h == pasteButton) {
                if (IsClipboardFormatAvailable(formatID)) {
                    OpenClipboard(hWnd);
                    HANDLE hCbMem = GetClipboardData(formatID);
                    HGLOBAL hProgMem = GlobalAlloc(GHND, GlobalSize(hCbMem));
                    if (hProgMem == 0) { break; }
                    LPVOID lpCbMem = GlobalLock(hCbMem);
                    if (lpCbMem == NULL) {
                        GlobalUnlock(hCbMem);
                        break;
                    }
                    LPVOID lpProgMem = GlobalLock(hProgMem);
                    if (lpProgMem == NULL) {
                        GlobalUnlock(hCbMem);
                        GlobalUnlock(hProgMem);
                        break;
                    }
                    lstrcpy(lpProgMem, lpCbMem);
                    GlobalUnlock(hCbMem);
                    GlobalUnlock(hProgMem);
                    CloseClipboard();
                    SetWindowText(textBox, lpProgMem);
                    GlobalFree(hProgMem);
                }
            }
            else if (h == cutButton) {
                TCHAR text[BUFFER_SIZE];
                GetWindowText(textBox, text, BUFFER_SIZE);
                putInClipboardWithCustomFormat(text, BUFFER_SIZE - 1);
                SetWindowText(textBox, _T(""));
            }
            else if (h == clearButton) {
                SetWindowText(textBox, _T(""));
            }
        }
        break;
    case WM_KEYDOWN:
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc,
            10, 10,
            greeting, (int)_tcslen(greeting));

        EndPaint(hWnd, &ps);
        break;
    case WM_SIZE:
        break;
    case WM_MOVE:
        break;
    case WM_CLOSE:
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