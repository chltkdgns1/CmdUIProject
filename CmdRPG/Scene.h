#pragma once
#include <iostream>
#include "GameLoofManager.h"
using namespace std;
class Scene {	
public:
	// 로드 이후에 GameLoofManager 루프가 진행됨
	void Load(){
		UnLoad();
		Start();
		GameLoofManager::StartGameLoof();
	}

	void UnLoad() {
		GameLoofManager::ExitGameLoof();
	}
	virtual void Start() = 0;
};