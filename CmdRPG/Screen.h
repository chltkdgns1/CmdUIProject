#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Screen {
public:
	static bool isFixedScreen;
	static int screenWidthSize;
	static int screenHeightSize;
	static PWINDOWINFO curInfo;

	static void FixedScreenSize();
};