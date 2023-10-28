#include "LobbyScene.h"

void LobbyScene::Start() 
{
	startGameMenuList.push_back(new UIButton(TransPosition(23, 5), 43, 5,  "Start Game"));
	startGameMenuList.push_back(new UIButton(TransPosition(23, 10), 43, 5, "Setting"));
	startGameMenuList.push_back(new UIButton(TransPosition(23, 15), 43, 5, "Record"));
	startGameMenuList.push_back(new UIButton(TransPosition(23, 20), 43, 5, "Exit"));

	/*startGameButton->OnClick = [](Object *btn)
	{
		((UIButton*)btn)->uiText->SetText("clicked");
	};*/
}

void LobbyScene::InitClickEvent() 
{

}