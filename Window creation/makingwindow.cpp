#include <GL/glu.h>
#include <windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;


LRESULT  CALLBACK WndProc(HWND hwnd, UINT msg1, WPARAM wParam, LPARAM lParam){
    switch (msg1)
    {
        case WM_CLOSE:
            PostQuitMessage(69);
            break;
        //: keydown recognises all keys, WM_CHAR only recognises charactors
        //: however WM_CHAR is case sensitive, KEYDOWN is not.
        
        case WM_CHAR:
        {
            string title;
            title.push_back((char)wParam);
            SetWindowText(hwnd,title.c_str());
            break;
        }
        case WM_KEYDOWN:
            if(wParam=='M'){
                
            }
            if(wParam==VK_ESCAPE){
                PostQuitMessage(420);
                break;
            }
            break;
        case WM_KEYUP:
        //you didnt see that
            if(wParam=='M'){
                SetWindowText(hwnd,"huh?");
            }
            break;
    }
    return DefWindowProc(hwnd,msg1,wParam,lParam);
}

int CALLBACK  WinMain( 
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance, 
    LPSTR lPCmdline, 
    int nCmdShow){
        const auto winClassName= "s_win";
        //todo to create window you need to register window class
        WNDCLASSEX winclass = {0};
        winclass.cbSize=sizeof(winclass);
        winclass.style=CS_OWNDC;
        winclass.lpfnWndProc=WndProc;
        winclass.cbWndExtra=0;
        winclass.cbClsExtra=0;
        winclass.hInstance=hInstance;
        winclass.hIcon=nullptr;
        winclass.hCursor=nullptr;
        winclass.hbrBackground=nullptr;
        winclass.lpszMenuName=nullptr;
        winclass.lpszClassName= winClassName;


        RegisterClassEx(&winclass);
        //* creating a window
        HWND firstWin=CreateWindowEx(
        0,  
        winClassName,
        "ButtonBoo",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        200,200,
        1280,720,//size of the window
        nullptr,nullptr
        ,hInstance,nullptr
        );
        ShowWindow(firstWin,SW_SHOW);
        MSG msg1;
        bool getmessage_reply;
        while(getmessage_reply=GetMessage(&msg1,nullptr,0,0)>0)
        {
            //:translate message - convert keys to WM_CHAR
            TranslateMessage(&msg1);
            DispatchMessage(&msg1);
        }
        if(getmessage_reply==-1){
            return -1;
        }
        else{
            return msg1.wParam;
        }
    }
