#include"DxLib.h"
#include"Input.h"
#include"SceneMgr.h"
#include"Stage.h"

#define PI 3.141592f

static int mImageHandle;
static int mImageMenu;
static int mImageCone;

static int MenuNumber = 0;

void Stage_Initialize() {
	mImageHandle = LoadGraph("images/stage1.png");
	mImageMenu = LoadGraph("images/menu.png");
	mImageCone = LoadGraph("images/cone.png");
}
void Stage_Finalize() {
	DeleteGraph(mImageHandle);
	DeleteGraph(mImageMenu);
	DeleteGraph(mImageCone);
}
void Stage_Update() {
	if (iKeyFlg & PAD_INPUT_DOWN) {
		if (++MenuNumber > 2) MenuNumber = 0;

	}
	if (iKeyFlg & PAD_INPUT_UP) {
		if (--MenuNumber < 0) MenuNumber = 2;
		if (++MenuNumber > 1) MenuNumber = 0;

	}
	if (iKeyFlg & PAD_INPUT_UP) {
		if (--MenuNumber < 0) MenuNumber = 1;
	}

	if (iKeyFlg == PAD_INPUT_1) {
		switch (MenuNumber) {
		case 0:
			SceneMgr_ChangeScene(eScene_StockGame);
			break;
		case 1:
			SceneMgr_ChangeScene(eScene_TimeGame);
			break;
		case 2:
			SceneMgr_ChangeScene(eScene_Menu);
			break;
		}
	}
}
void Stage_Draw() {
	DrawGraph(0, 0, mImageHandle, FALSE);
	DrawGraph(0, 0, mImageHandle, FALSE);

	DrawGraph(120, 240, mImageMenu, TRUE);
	DrawRotaGraph(90, 260 + MenuNumber * 40, 0.7f, PI / 2, mImageCone, TRUE);
}