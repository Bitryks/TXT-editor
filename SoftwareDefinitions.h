#pragma once

#define OnMenuAction1			1
#define OnMenuAction2			2
#define OnMenuAction3			3
#define OnExitSoftware        4
#define OnClearField          5

HWND heditControl;

LRESULT CALLBACK SoftWareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGcolor, HCURSOR Cursor, HINSTANCE hinst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddMenus(HWND hWnd);
void MAinWndAddWidgets(HWND hWnd);
