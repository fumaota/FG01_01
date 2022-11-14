#include "DxLib.h"
#include"talk.h"
#include"PlayerChat.h"
#include"EnemyChat.h"
#include"GameOver.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "07_connect mail";

// �E�B���h�E����
const int WIN_WIDTH = 600;
// �E�B���h�E�c��
const int WIN_HEIGHT = 900;

enum GAMESCENE
{
	Title,
	Level1,
	Level2,
	Level3,
	Level4,
	Level5,
	End,
	Clear,
	Ruru
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	
	ChangeWindowMode(TRUE);                   // �E�B���h�E���[�h�ɐݒ�
	SetWindowSizeChangeEnableFlag(true, true);// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetMainWindowText(TITLE);                 // �^�C�g����ύX
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);  // ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetWindowSizeExtendRate(1.0);             // ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetBackgroundColor(0, 0, 0);     // ��ʂ̔w�i�F��ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);            // (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetFontSize(20);
	if (DxLib_Init() == -1) { return -1; }    // DXlib�̏�����

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int backGraph = LoadGraph("Resource\\back.png");
	int textGraph = LoadGraph("Resource\\text.png");
	int titleGraph = LoadGraph("Resource\\title.png");
	int endGraph = LoadGraph("Resource\\end.png");
	int clearGraph = LoadGraph("Resource\\clear.png");
	int ruruGraph = LoadGraph("Resource\\ru-ru.png");

	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	int sceneState = 0;

	Talk* talk_ = new Talk;
	PlayerChat* playerchat_ = new PlayerChat;
	EnemyChat* enemychat_ = new EnemyChat;
	//GameOver* gameover_ = new GameOver;

	//�^�C�}�[
	int time = 0;
	int timer = 120;

	int count = 0;

	char keys[256] = { 0 };   // �ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };// 1���[�v(�t���[��)�O�̃L�[�{�[�h���

	int GCount = 0;
	int GFlag = 0;
	// �Q�[�����[�v
	while (true)
	{
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		GetHitKeyStateAll(keys);// �ŐV�̃L�[�{�[�h�����擾
		ClearDrawScreen();      // ��ʃN���A

		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		
		time++;
		if (time >= 60) {
			timer -= 1;
			time = 0;
		}

		switch (sceneState)
		{
		case Title:
			talk_->Initialize();

			playerchat_->Initialize();

			enemychat_->Initialize();

			DrawGraph(0,0,titleGraph,TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Ruru;
			}
			break;
		case Level1:
			talk_->Update(keys);

			playerchat_->Update(keys, oldkeys);

			enemychat_->Update(keys, oldkeys);

			//gameover_->Update(keys, oldkeys, GCount, GFlag);
			

			if (playerchat_->chatFalse == 2) {
				sceneState = Clear;
			}
			break;
		case End:
			DrawGraph(0, 0, endGraph, TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Title;
			}
			break;
		case Clear:
			DrawGraph(0, 0, clearGraph, TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Title;
			}
			break;
		case Ruru:
			DrawGraph(0, 0, ruruGraph, TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Level1;
			}
			break;
		}

		// �`�揈��

		if (sceneState == Level1) {
			talk_->Draw();

			playerchat_->Draw();

			enemychat_->Draw();

			//gameover_->Draw(GFlag);

			DrawGraph(0, 0, backGraph, TRUE);

			DrawFormatString(200, 30, GetColor(0, 0, 0), "�A������:�Ƃ�����");

			DrawFormatString(10, 110, GetColor(0, 0, 0), "count:%d",GCount);
			DrawFormatString(10, 220, GetColor(0, 0, 0), "flag:%d",GFlag);
		}
		

		//DrawFormatString(200, 0, GetColor(255, 255, 255), "timer=%d", timer);
		//---------  �����܂łɃv���O�������L�q  ---------//

		ScreenFlip();// (�_�u���o�b�t�@)����
		WaitTimer(20);// 20�~���b�ҋ@(�^��60FPS)
		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}
		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	DxLib_End();// Dx���C�u�����I������

	return 0;// ����I��
}
