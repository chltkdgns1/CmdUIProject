#pragma once
#include <iostream>
#include <map>
#include "ConsoleImage.h"
#include "Mouse.h"
#include "Position.h"
using namespace std;

class Object{
protected:
	virtual void Enable() = 0;
	virtual void Disable() = 0;

	bool realActive;
	bool changed;

	int peekImgPage = 0;

public:
	static int maxNum;
	static map<int, Object*> objMap;

	void(*OnClick)(Object*);

	int numbering;

	bool isActive;

	TransPosition centerPos;
	vector<ConsoleImage> consoleImgList;

	static void clear() {
		for (auto obj : objMap) {
			obj.second ->Destory(obj.second);
		}
		objMap.clear();
	}

	Object() {
		isActive = true;
		realActive = false;
		changed = false;
		numbering = maxNum;
		objMap[numbering] = this;
		maxNum++;
		OnClick = NULL;
	}

	void SetActive(bool isActive) {
		this->isActive = isActive;
	}

	virtual void Destory(Object *mine = NULL) {
		Disable();
		objMap.erase(numbering);
		if (mine == NULL || this != mine) {
			return;
		}
		delete mine;
		mine = NULL;
	}

	virtual void Render() {
		if (realActive != isActive || changed == true) {
			realActive = isActive;
			changed = false;

			if (realActive) {
				Enable();
			}
			else {
				Disable();
			}
		}
	}

	virtual bool Inside(TransPosition pos)
	{
		if (consoleImgList.size())
			return false;

		ConsoleImage& consoleImgTemp = consoleImgList[peekImgPage];
		for (int i = 0; i < consoleImgTemp.pixelList.size(); i++)
		{
			if (consoleImgTemp.pixelList[i].pos.x == pos.x && consoleImgTemp.pixelList[i].pos.y == pos.y)
			{
				return true;
			}
		}
		return false;
	}
};
