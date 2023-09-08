#include <Windows.h>
#include"resource1.h"
#include "SoftwareDefinitions.h"


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, 
		LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"MAinWndClass", SoftWareMainProcedure);

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };
	
	CreateWindow(L"MainWndClass", L"First C++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 250, NULL, NULL, NULL, NULL); 
	
	
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGcolor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure)
{
	WNDCLASS NWC = { 0 };

	NWC.hCursor = Cursor;
	NWC.hIcon = Icon;
	NWC.hInstance = hinst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGcolor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK SoftWareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp )
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (wp)
		{
		case OnMenuAction1:
			MessageBoxA(hWnd, "Menu 1 was clicked!", "Menu worked", MB_OK);
			break;
		case OnClearField:
			SetWindowTextA(heditControl, "");
			break;
		case OnExitSoftware:
			PostQuitMessage(0);
			break;
		default: break;
		}
		break;

	case WM_CREATE:
		MainWndAddMenus(hWnd);
		MAinWndAddWidgets(hWnd);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWnd, msg, wp, lp);
	}



}

void MainWndAddMenus(HWND hWnd)
{
	HMENU RootMenu = CreateMenu();


	HMENU SubMenu = CreateMenu();
	HMENU SubActionMenu = CreateMenu();





	AppendMenu(SubMenu, MF_STRING, OnClearField, L"Clear");
	AppendMenu(SubMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenu, MF_STRING, OnExitSoftware, L"Exit");

	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"File");
	AppendMenu(RootMenu, MF_STRING, (UINT_PTR)SubMenu, L"Help");

	SetMenu(hWnd, RootMenu);

}
void MAinWndAddWidgets(HWND hWnd)
{
	CreateWindowA("edit", "STATUS:Hello Window!", WS_VISIBLE | WS_CHILD| ES_CENTER, 140, 5, 350, 30, hWnd, NULL, NULL, NULL);

	heditControl = CreateWindowA("edit", "Yhis is EDIT control", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 40, 470, 120, hWnd, NULL, NULL, NULL);

	CreateWindowA("button", "Clear", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 120, 30, hWnd, (HMENU)OnClearField, NULL, NULL);

}
