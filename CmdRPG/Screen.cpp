#include "Screen.h"

bool Screen::isFixedScreen = true;
int Screen::screenWidthSize = 401;
int Screen::screenHeightSize = 401;
PWINDOWINFO Screen::curInfo;

void Screen::FixedScreenSize() 
{
	if (curInfo == NULL)
	{
		curInfo = new WINDOWINFO();
		GetWindowInfo(GetConsoleWindow(), curInfo);
	}

	int width = curInfo->rcWindow.right - curInfo->rcWindow.left;
	int height = curInfo->rcWindow.bottom - curInfo->rcWindow.top;

	if (screenWidthSize != width || screenHeightSize != height)
	{
		SetWindowPos(GetConsoleWindow(), 0, 0, 0, screenWidthSize, screenHeightSize, SWP_NOMOVE | SWP_SHOWWINDOW);
	}
}