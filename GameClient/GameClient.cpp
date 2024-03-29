﻿// GameClient.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "GameClient.h"
#include "GameLibrary.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING]       = L"Client";            // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING] = L"Client";            // 기본 창 클래스 이름입니다.

MouseInput* mouseManager = new MouseInput();
KeyboardInput* keyboardManager = new KeyboardInput("Setting.ini", rpgKeySetting);

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMECLIENT));
    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMECLIENT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   RECT rect;
   rect.left = 0;
   rect.top = 0;
   rect.right = DEV_WIDTH;
   rect.bottom = DEV_HEIGHT;
   DWORD dwStyle = WS_OVERLAPPEDWINDOW;
   AdjustWindowRect(&rect, dwStyle, false);

   float width = (rect.right - rect.left) * 1.0f;
   float height = (rect.bottom - rect.top) * 1.0f;

   int monitorWidth = GetSystemMetrics(SM_CXSCREEN);
   int monitorHeight = GetSystemMetrics(SM_CYSCREEN);
   float windowPosX = (monitorWidth - width) / 2.0f;
   float windowPosY = (monitorHeight - height) / 2.0f;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, dwStyle,
       int(windowPosX), int(windowPosY), int(width), int(height), nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CREATE:
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

        // keyboard
    case WM_KEYDOWN:
        keyboardManager->updateKeyboardInput(KeyStateDown, int(wParam));
        break;
    case WM_KEYUP:
        keyboardManager->updateKeyboardInput(KeyStateUp, int(wParam));
        break;

        // mouse
    case WM_LBUTTONDOWN:
        mouseManager->updateMouseClick(Left, KeyStateDown, createPoint2D(LOWORD(lParam), HIWORD(lParam)));
        break;
    case WM_LBUTTONUP:
        mouseManager->updateMouseClick(Left, KeyStateUp, createPoint2D(LOWORD(lParam), HIWORD(lParam)));
        break;
    case WM_RBUTTONDOWN:
        mouseManager->updateMouseClick(Right, KeyStateDown, createPoint2D(LOWORD(lParam), HIWORD(lParam)));
        break;
    case WM_RBUTTONUP:
        mouseManager->updateMouseClick(Right, KeyStateUp, createPoint2D(LOWORD(lParam), HIWORD(lParam)));
        break;
    case WM_MOUSEMOVE:
        mouseManager->updateMouseMove(KeyStateMove, createPoint2D(LOWORD(lParam), HIWORD(lParam)));
        break;
    case WM_MOUSEWHEEL:
        mouseManager->updateMouseWheel(GET_WHEEL_DELTA_WPARAM(wParam));
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
