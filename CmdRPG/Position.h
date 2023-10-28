#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class TransPosition {
public:
	int x, y, z;

	TransPosition()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	TransPosition(int x, int y, int z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	TransPosition(TransPosition* pos)
	{
		if (pos == NULL) 
		{
			TransPosition();
			return;
		}

		this->x = pos->x;
		this->y = pos->y;
		this->z = pos->z;
	}

	TransPosition(const TransPosition&pos) {
		this->x = pos.x;
		this->y = pos.y;
		this->z = pos.z;
	}

	bool SetPos() 
	{
		if (x < 0 || y < 0)
			return false;

		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		return true;
	}
};