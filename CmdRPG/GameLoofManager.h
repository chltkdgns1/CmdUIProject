#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "UI.h"
#include "Renderer.h"
#include "Screen.h"
using namespace std;

class GameLoofManager {
private:
	static bool isLoof;

	static void SetLoofFlag(bool isLoof) {
		GameLoofManager::isLoof = isLoof;
	}
public:
	static void Update()
	{
		Renderer::Render();
		MouseManager::OnLClickEvent();
	}

	static void StartGameLoof() 
	{
		isLoof = true;

		if (Screen::isFixedScreen)
		{
			Screen::FixedScreenSize();
		}

		while (isLoof) 
		{
			Update();

			if (Screen::isFixedScreen)
			{
				Screen::FixedScreenSize();
			}
		}
	}

	static void ExitGameLoof()
	{
		SetLoofFlag(false);
	}
};