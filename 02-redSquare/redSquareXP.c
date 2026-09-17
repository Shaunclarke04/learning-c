#include <windows.h>

/* Event handler */
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    int x;
    int y;

    switch (msg)
    {
        /* Draw pixels */
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);

            /* SQUARE!! */
            for (y = 100; y < 200; y++)
            {
                for (x = 100; x < 200; x++)
                {
                    SetPixel(hdc, x, y, RGB(255, 0, 0));
                }
            }

            EndPaint(hwnd, &ps);
            return 0;

        /* Quit on close */
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

/* Main */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASS wc = {0};
    HWND hwnd;
    MSG msg;

    /* Window class */
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindow";

    RegisterClass(&wc);

    /* Create window */
    hwnd = CreateWindow(
        "MyWindow",
        "Hello!",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL, NULL,
        hInstance,
        NULL);

    ShowWindow(hwnd, nShowCmd);

    /* Message loop */
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
