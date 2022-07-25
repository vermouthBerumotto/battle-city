#include <windows.h>
#include "head.h"

extern void Paint(HWND hWnd);
extern void SelectItem(WPARAM wparam, HWND hWnd);
extern void MainTankAction(HWND hWnd, WPARAM wparam);
extern BOOL start;

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam);





int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	WNDCLASS wndClass;
	MSG msg;
	HWND hWnd;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hCursor = LoadCursorA(NULL, IDI_APPLICATION);
	wndClass.hIcon = (HICON)LoadImageA(NULL, "tank.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = "battle city";
	wndClass.style = NULL;
	wndClass.hbrBackground = (HBRUSH)(COLOR_ACTIVEBORDER);

	RegisterClassA(&wndClass);

	hWnd = CreateWindowA("battle city", "battle city", WS_OVERLAPPEDWINDOW, X0, Y0, W0, H0, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, SW_SHOW);

	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Other program lines to do some work
		}
	}
	return msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam)
{


	switch (msg)
	{
	case WM_CREATE:
	{

	}break;

	case WM_PAINT:
	{
		Paint(hWnd);
	}break;

	case WM_KEYDOWN:
	{
		if (start == FALSE)
			SelectItem(wparam, hWnd);
		else
			MainTankAction(hWnd, wparam);
	}break;

	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	}
	return DefWindowProcA(hWnd, msg, wparam, lparam);
}



