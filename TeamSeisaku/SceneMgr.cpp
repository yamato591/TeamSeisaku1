#include"DxLib.h"
#include"Help.h"
#include"StockGame.h"
#include"TimeGame.h"
#include"Menu.h"
#include"SceneMgr.h"
#include"Player.h"
#include"Stage.h"

static eScene mScene = eScene_Menu;
static eScene mNextScene = eScene_None;

static void SceneMgr_InitializeModule(eScene scene);
static void SceneMgr_FinalizeModule(eScene scene);

void SceneMgr_Initialize() {
	SceneMgr_InitializeModule(mScene);
}
void SceneMgr_Finalize() {
	SceneMgr_FinalizeModule(mScene);
}
void SceneMgr_Update() {
	if (mNextScene != eScene_None) {
		SceneMgr_FinalizeModule(mScene);
		mScene = mNextScene;
		mNextScene = eScene_None;
		SceneMgr_InitializeModule(mScene);
	}
	switch (mScene) {
	case eScene_Menu:
		Menu_Update();
		break;
	case eScene_StockGame:
		StockGame_Update();
		break;
	case eScene_TimeGame:
		TimeGame_Update();
		break;
	case eScene_Help:
		Help_Update();
		break;
	case eScene_Player:
		Player_Update();
		break;
	case eScene_Stage:
		Stage_Update();
		break;
	}
}

void SceneMgr_Draw() {
	switch (mScene) {
	case eScene_Menu:
		Menu_Draw();
		break;
	case eScene_StockGame:
		StockGame_Draw();
		break;
	case eScene_TimeGame:
		TimeGame_Draw();
		break;
	case eScene_Help:
		Help_Draw();
		break;
	case eScene_Player:
		Player_Draw();
		break;
	case eScene_Stage:
		Stage_Draw();
		break;
	}
}

void SceneMgr_ChangeScene(eScene NextScene) {
	mNextScene = NextScene;
}
static void SceneMgr_InitializeModule(eScene scene) {
	switch (scene) {
	case eScene_Menu:
		Menu_Initialize();
		break;
	case eScene_StockGame:
		StockGame_Initialize();
		break;
	case eScene_TimeGame:
		TimeGame_Initialize();
		break;
	case eScene_Help:
		Help_Initialize();
		break;
	case eScene_Player:
		Player_Initialize();
		break;
	case eScene_Stage:
		Stage_Initialize();
		break;
	}
}
static void SceneMgr_FinalizeModule(eScene scene) {
	switch (scene) {
	case eScene_Menu:
		Menu_Finalize();
		break;
	case eScene_Help:
		Help_Finalize();
		break;
	case eScene_Player:
		Player_Finalize();
		break;
	case eScene_Stage:
		Stage_Finalize();
		break;
	case eScene_StockGame:
		StockGame_Finalize();
		break;
	case eScene_TimeGame:
		TimeGame_Finalize();
		break;
	}
}
int SceneMgr_GameEnd_Status() {
	if (mScene == eScene_End) {
		return 1;
	}
	else {
		return 0;
	}
}