
#include <stdio.h>
#include <iostream>

#ifdef _WIN32
#pragma comment(linker, "/subsystem:windows")
#define VK_USE_PLATFORM_WIN32_KHR
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#endif

#include "core_base.h"
#include "BD_core.h"


BD_core *BD;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (BD != NULL) {
		BD->handleMessages(hWnd, uMsg, wParam, lParam);
	}
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

#ifdef _WIN32
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#endif
{
	BD = new BD_core(true);
#ifdef _WIN32
	BD->setupWindow(hInstance, WndProc);
#endif

	BD->initSwapchain();
	BD->prepare();

	BD->renderLoop();
	delete (BD);
	system("pause");
	return 0;
}