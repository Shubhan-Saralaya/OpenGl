#include <GL/glu.h>
#include <tchar.h>
#include <GL/gl.h>
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int CALLBACK  WinMain( 
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance, 
    LPSTR lPCmdline, 
    int nCmdShow){
        cout<<"Hello World";
        const auto winClassName= _T("s_win");
        //todo to create window you need to register window class
        WNDCLASSEX winclass = {0};
        winclass.cbSize=sizeof(winclass);
        winclass.style=CS_OWNDC;
        winclass.lpfnWndProc=DefWindowProc;
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
        _T("ButtonBoo"),
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        500,500,
        1280,720,//size of the window
        nullptr,nullptr
        ,hInstance,nullptr
        );
        ShowWindow(firstWin,SW_SHOW);
        
        return 0;
    }
