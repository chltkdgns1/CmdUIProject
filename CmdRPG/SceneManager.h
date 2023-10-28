#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "UI.h"
#include "Scene.h"
#include "LobbyScene.h"
using namespace std;

class SceneManager {
public:	
	static SceneManager* instance;

private:
	string sceneName;
	map<string, Scene*> sceneMap;

	void SetSceneName(string sceneName) {
		this->sceneName = sceneName;
	}

	void SetSceneList() {
		sceneMap["LobbyScene"] = new LobbyScene();
	}

public:
	static SceneManager* GetInstance() {
		if (instance == NULL) {
			instance = new SceneManager();
		}
		return instance;
	}

	void MoveScene(string moveTargetSeneName) {
		if(sceneName.empty() == false && sceneName != "")
			sceneMap[sceneName]->UnLoad();

		SetSceneName(moveTargetSeneName);
		StartScene();
	}

	void StartScene() {
		Object::clear();
		sceneMap[sceneName]->Load();
	}

	SceneManager() {
		SetSceneList();
	}
};