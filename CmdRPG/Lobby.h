#pragma once
#include <iostream>
using namespace std;

class LobbyUI {
public:
	void PrintLobby();
};

// �κ� ����
class Lobby { 
private:
	static Lobby* instance;
public:
	LobbyUI lobbyUI;
	Lobby* GetInstance();
};

Lobby Lobby::* instance = NULL;
