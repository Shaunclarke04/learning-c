#include <windows.h>

//eventHander
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) //something happened
    {
        //draw pixels
        case WM_PAINT: 
        {
            //start draw
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            //SQUARE!!
            for (int y = 100; y < 200; y++)
            {
                for (int x = 100; x < 200; x++)
                {
                    SetPixel(hdc, x, y, RGB(255, 0, 0));
                }
            }
            
            //stop draw
            EndPaint(hwnd, &ps);
            return 0;
        }

        //quit on close
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam); //let windows itself handle it
}

//main
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASS wc = {0}; //structure (0=default)
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //background
    wc.lpfnWndProc = WindowProc; //call eventhandler(WindowProc)
    wc.hInstance = hInstance; //assign window to executable
    wc.lpszClassName = "MyWindow"; //window class

    RegisterClass(&wc); //initialize - Tell Windows about this window class

    //create window
    HWND hwnd = CreateWindow(
        "MyWindow", //class
        "Hello!", //title
        WS_OVERLAPPEDWINDOW, //window type
        CW_USEDEFAULT, CW_USEDEFAULT, //default location
        800, 600, //size
        NULL, NULL, //parentWindow/Menu
        hInstance, //Handle to this executable
        NULL); //finish

    ShowWindow(hwnd, nShowCmd); //show window

    MSG msg; //msg container

    while (GetMessage(&msg, NULL, 0, 0)) //loop & wait for event
    {
        TranslateMessage(&msg); //Converts raw keyboard input into characters.
        DispatchMessage(&msg); //call relevent WindowProc
    }

    return 0; //end
}