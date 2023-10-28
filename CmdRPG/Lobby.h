#pragma once
#include <iostream>
using namespace std;

class LobbyUI {
public:
	void PrintLobby();
};

// 로비 로직
class Lobby { 
private:
	static Lobby* instance;
public:
	LobbyUI lobbyUI;
	Lobby* GetInstance();
};

Lobby Lobby::* instance = NULL;
