#pragma once
#include <iostream>
#include "GameLoofManager.h"
using namespace std;
class Scene {	
public:
	// �ε� ���Ŀ� GameLoofManager ������ �����
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