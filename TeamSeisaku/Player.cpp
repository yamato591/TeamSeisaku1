#include"DxLib.h"
#include"SceneMgr.h"
#include"Input.h"
#include"Player.h"

static int mImagePlayer;

void Player_Initialize() {
	mImagePlayer = LoadGraph("images/player.png");
}
void Player_Finalize() {
	DeleteGraph(mImagePlayer);
}
void Player_Update() {

}
void Player_Draw() {
	DrawGraph(100, 100, mImagePlayer, TRUE);
}