#pragma once

#include <iostream>
#include <map>
#include <Windows.h>
#include "Object.h"
using namespace std;

class Object;

class MousePos {
public:
	int x, y;

	MousePos(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class MouseManager {
protected :
	static HANDLE hCout;
	static HANDLE hCin;
public:
	static map<int, Object*> event;
	static void AddMouseEvent(int objNum, Object* obj);
	static void DeleteMouseEvent(int objNum, Object* obj);
	static void Clear();
	static void MouseSetting();
	static bool OnLClickEvent();
	static bool OnRClickEvent();
	static void SendEvent(MousePos pos);
};