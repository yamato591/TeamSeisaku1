#include "DxLib.h"
#include"StockGame.h"
#include"TimeGame.h"

int	iOldKey;	// �O��̓��̓L�[
int	iNowKey;	// ����̓��̓L�[
int	iKeyFlg;	// ���̓L�[���

int iMouseX;
int iMouseY;

/***********************************************
 * �L�[���͎擾�֐�
 ***********************************************/
void InputKey(void) {
    // ���̓L�[�擾
    iOldKey = iNowKey;
    iNowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
    iKeyFlg = iNowKey & ~iOldKey;
}