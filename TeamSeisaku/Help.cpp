#include"Help.h"
#include"SceneMgr.h"
#include"DxLib.h"
#include"Input.h"

static int mImageHandle;

void Help_Initialize() {
	mImageHandle = LoadGraph("images/Scene_Config.png");

}
void Help_Finalize() {
	DeleteGraph(mImageHandle);
}
void Help_Update() {
	if (iKeyFlg == PAD_INPUT_1) {
		SceneMgr_ChangeScene(eScene_Menu);
	}
}
void Help_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
}