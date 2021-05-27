#include"TimeGame.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Player.h"
#include"Input.h"

static int mImageHandle;

static int MenuNumber = 0;


void TimeGame_Initialize() {
	mImageHandle = LoadGraph("images/stage2.png");

	Player_Initialize();
}
void TimeGame_Finalize() {
	DeleteGraph(mImageHandle);

	Player_Finalize();
}
void TimeGame_Update() {
	if ((CheckHitKey(KEY_INPUT_ESCAPE) != 0)) {
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
	Player_Update();
}
void TimeGame_Draw() {
	Player_Draw();
	DrawGraph(0, 0, mImageHandle, FALSE);

}