#pragma once
#include <iostream>
#include "Scene.h"
#include "UI.h"
#include "Object.h"
using namespace std;

class LobbyScene : public Scene {
public:
	vector<UIButton*> startGameMenuList;

	virtual void Start();
	void InitClickEvent();
};
