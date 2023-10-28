#include "Mouse.h"
#include "Position.h"

void MouseManager::AddMouseEvent(int objNum, Object *obj)
{
	event[objNum] = obj;
}

void MouseManager::DeleteMouseEvent(int objNum, Object* obj)
{
	event.erase(objNum);
}

void MouseManager::Clear()
{
	event.clear();
}

void MouseManager::MouseSetting() {
	hCin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hCin, &mode);
	SetConsoleMode(hCin, mode | ENABLE_MOUSE_INPUT);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode) | ENABLE_MOUSE_INPUT);

	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = false;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void MouseManager::SendEvent(MousePos pos)
{
	for (auto obj : event) 
	{
		bool isInside = obj.second->Inside(TransPosition(pos.x, pos.y));

		if (isInside) 
		{
			if (obj.second->OnClick != NULL)
			{
				obj.second->OnClick(obj.second);
			}
		}
	}
}

bool MouseManager::OnLClickEvent()
{
	INPUT_RECORD rec;
	DWORD dwRead;
	if (ReadConsoleInput(hCin, &rec, 1, &dwRead))
	{
		if (rec.EventType == MOUSE_EVENT)
		{
			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) 
			{
				SendEvent(MousePos(rec.Event.MouseEvent.dwMousePosition.X, rec.Event.MouseEvent.dwMousePosition.Y));
			}
		}
		return true;
	}
	return false;
}

bool MouseManager::OnRClickEvent()
{
	return false;
}

map<int, Object*> MouseManager::event;
HANDLE MouseManager::hCout;
HANDLE MouseManager::hCin;