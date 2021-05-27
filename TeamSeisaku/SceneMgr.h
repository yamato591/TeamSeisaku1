#pragma once

typedef enum {
	eScene_Menu,
	eScene_StockGame,
	eScene_TimeGame,
	eScene_Help,
	eScene_End,
	eScene_Player,
	eScene_Stage,

	eScene_None,
}eScene;

void SceneMgr_Initialize();
void SceneMgr_Finalize();
void SceneMgr_Update();
void SceneMgr_Draw();

void SceneMgr_ChangeScene(eScene nextScene);

int SceneMgr_GameEnd_Status();
