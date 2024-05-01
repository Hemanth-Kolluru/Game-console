#include <iostream>
#include <windows.h>
using namespace std;
bool running = true;
void* buffer_memory;
int buffer_width;
int buffer_height;
BITMAPINFO buffer_bitmap_info;
LRESULT CALLBACK window_callback(HWND unnamedParam1,UINT unnamedParam2,WPARAM unnamedParam3,LPARAM unnamedParam4)
{
    LRESULT result = 0;
    switch(unnamedParam2)
    {
        case WM_CLOSE:
        case WM_DESTROY:
        {
            running = false;
        } break;
        case WM_SIZE:
        {
            RECT rect;
            GetClientRect(unnamedParam1,&rect);
            int buffer_width = rect.right - rect.left;
            int buffer_height = rect.bottom - rect.top;
            int buffer_size = buffer_width * buffer_height * sizeof(unsigned int);
            if(buffer_memory) VirtualFree(buffer_memory, 0 ,MEM_RELEASE);
            buffer_memory = VirtualAlloc(0,buffer_size,MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            buffer_bitmap_info.bmiHeader.biSize = sizeof(buffer_bitmap_info.bmiHeader);
            buffer_bitmap_info.bmiHeader.biWidth = buffer_width;
            buffer_bitmap_info.bmiHeader.biPlanes = 1;
            buffer_bitmap_info.bmiHeader.biBitCount = 32;
            buffer_bitmap_info.bmiHeader.biCompression = BI_RGB;
        } break;
        default:
        {
            result = DefWindowProc(unnamedParam1,unnamedParam2,unnamedParam3,unnamedParam4);
        }
    }
    return result;
}

int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    WNDCLASS window_class = {};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpszClassName = "Game Window";
    window_class.lpfnWndProc = window_callback;
    RegisterClass(&window_class);
    HWND window = CreateWindowA(window_class.lpszClassName, "My First Game",WS_OVERLAPPEDWINDOW | WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,1200,720,0,0,hInstance,0);
    HDC hdc = GetDC(window);
    while(running)
    {
        MSG message;
        while(PeekMessage(&message,window,0,0,PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        unsigned int* pixel = (unsigned int*)buffer_memory;
        for(int i=0;i<buffer_height;i++)
        {
            for(int j=0;j<buffer_width;j++)
            {
                *pixel++ = 0x00FFFF;
            }
        }
        StretchDIBits(hdc,0,0,buffer_width,buffer_height,0,0,buffer_width,buffer_height,buffer_memory,&buffer_bitmap_info,DIB_RGB_COLORS,SRCCOPY);
    }
}