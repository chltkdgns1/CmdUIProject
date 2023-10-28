#include "UI.h"

void UIArea::Print() 
{
	ConsoleImage& consoleImgTemp = consoleImgList[peekImgPage];
	for (int i = 0; i < consoleImgTemp.pixelList.size(); i++)
	{
		consoleImgTemp.pixelList[i].Print();
	}
}

void UIArea::Erase()
{
	ConsoleImage& consoleImgTemp = consoleImgList[peekImgPage];
	for (int i = 0; i < consoleImgTemp.pixelList.size(); i++)
	{
		consoleImgTemp.pixelList[i].Erase();
	}
}

void UIButton::GetButtonArea() 
{
	GetRect();
	for (int i = 0; i < width; i++) 
	{
		consoleImgList[0].pixelList.push_back(Pixels(TransPosition(left + i,top), '*'));
		consoleImgList[0].pixelList.push_back(Pixels(TransPosition(left + i, bottom), '*'));
	}

	for (int i = 0; i < height; i++) 
	{
		consoleImgList[0].pixelList.push_back(Pixels(TransPosition(left, top + i), '*'));
		consoleImgList[0].pixelList.push_back(Pixels(TransPosition(right, top + i), '*'));
	}
}

void UIButton::GetRect()
{
	top = centerPos.y - height / 2;
	left = centerPos.x - width / 2;
	bottom = centerPos.y + height / 2;
	right = centerPos.x + width / 2;
}

void UIButton::ChangeEvenSize()
{
	width = width % 2 == 0 ? width + 1 : width;
	height = height % 2 == 0 ? height + 1 : height;
}

void UIText::Print() 
{
	int len = text.length();
	int left = len / 2;

	TransPosition pos(this->centerPos);
	pos.x -= left;

	if (pos.SetPos())
	{
		cout << text;
	}
}

void UIText::Erase() 
{
	int len = text.length();
	int left = len / 2;

	TransPosition pos(this->centerPos);
	pos.x -= left;

	if (pos.SetPos())
	{
		for (int i = 0; i < len; i++) 
		{
			cout << " ";
		}
	}
}

bool UIText::Inside(TransPosition pos) {
	return false;
}