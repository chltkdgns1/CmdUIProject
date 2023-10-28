#pragma once
#include <iostream>
#include <vector>
#include "Position.h"
using namespace std;

class Pixels {
public:
	TransPosition pos;
	char ch;

	Pixels(TransPosition pos, char ch)
	{
		this->ch = ch;
		this->pos = pos;
	}

	void Print()
	{
		if (pos.SetPos() == false)
			return;

		cout << ch;
	}

	void Erase()
	{
		if (pos.SetPos() == false)
			return;

		cout << " ";
	}
};

class ConsoleImage {
protected :

public:
	vector<Pixels> pixelList;

	void Clear() 
	{
		pixelList.clear();
	}

	void Copy(ConsoleImage& img) 
	{
		pixelList.clear();
		for (int i = 0; i < img.pixelList.size(); i++)
		{
			pixelList.push_back(img.pixelList[i]);
		}
	}
};