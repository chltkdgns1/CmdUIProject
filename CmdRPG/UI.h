#pragma once
#include "Position.h"
#include "Object.h"
#include "ConsoleImage.h"
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class UI : public Object
{
protected:
	virtual void Enable() 
	{
		Print();
	}
	virtual void Disable()
	{
		Erase();
	}
	virtual void Print() = 0;
	virtual void Erase() = 0;
public:
	UI(TransPosition centerPos) : Object()
	{
		this->centerPos = centerPos;
	}
};

class UIArea : public UI {
protected:
	virtual void Print();
	virtual void Erase();
public:
	UIArea(TransPosition centerPos) : UI(centerPos)
	{
	
	}

	UIArea(TransPosition centerPos, ConsoleImage &consoleImg) : UI(centerPos)
	{
		this->centerPos = centerPos;

		peekImgPage = 0;
		consoleImgList.clear();
		consoleImgList.push_back(ConsoleImage());
		consoleImgList[peekImgPage].Copy(consoleImg);
	}

	UIArea(TransPosition centerPos, vector<ConsoleImage>& consoleImgs) : UI(centerPos)
	{
		this->centerPos = centerPos;

		peekImgPage = 0;
		consoleImgList.clear();

		for (int i = 0; i < consoleImgs.size(); i++) 
		{
			consoleImgList.push_back(consoleImgs[i]);
		}
	}
};

class UIText : public UI {
protected:
	virtual void Print();
	virtual void Erase();
public:
	string text;

	UIText(string text, TransPosition centerPos) : UI(centerPos)
	{
		this->text = text;
	}

	virtual bool Inside(TransPosition pos);

	void SetText(string text) 
	{
		this->text = text;
		changed = true;
	}
};

class UIButton : public UIArea{
protected:
	void GetButtonArea();
	void ChangeEvenSize();
	void GetRect();
	int top;
	int left;
	int bottom;
	int right;
	int width = 10;
	int height = 8;
public:
	UIText* uiText;

	UIButton(TransPosition centerPos, int width, int height, string caption = "") : UIArea(centerPos)
	{
		this->width = width;
		this->height = height;
		OnClick = NULL;
		uiText = new UIText(caption, centerPos);
		ChangeEvenSize();
		GetButtonArea();
		MouseManager::AddMouseEvent(numbering, this);
	}

	UIButton(TransPosition centerPos, ConsoleImage& consoleImg, string caption = "") : UIArea(centerPos, consoleImg)
	{
		OnClick = NULL;
		uiText = new UIText(caption, centerPos);
		MouseManager::AddMouseEvent(numbering, this);
	}
};