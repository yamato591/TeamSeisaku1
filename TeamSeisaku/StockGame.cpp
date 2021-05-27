#include"StockGame.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Player.h"
#include"Input.h"

static int mImageHandle;

static int MenuNumber = 0;


void StockGame_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Game.png");

	Player_Initialize();
}
void StockGame_Finalize() {
	DeleteGraph(mImageHandle);

	Player_Finalize();
}
void StockGame_Update() {
	if ((CheckHitKey(KEY_INPUT_ESCAPE) != 0)) {
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	Player_Update();
}
void StockGame_Draw() {
	Player_Draw();
	DrawGraph(0, 0, mImageHandle, FALSE);

}