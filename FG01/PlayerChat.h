#pragma once
#include"DxLib.h"

class PlayerChat 
{
public:
	PlayerChat() {}
	~PlayerChat(){}
	
	void Initialize();
	void Update(char *keys, char* oldkeys);
	void Draw();

	int chatSendFlag[20];

	int chatFalse = 0;
private:
	char keys[256] = { 0 };   // �ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };// 1���[�v(�t���[��)�O�̃L�[�{�[�h���

	int playerPosX[10];
	int playerPosY[10];

	int chatAnser = 0;
	int chatchose = 0;

	int sceneState = 0;
	//��
	int chattime;

	int chatSendCount = 0;

	int ChatScrollY = 0;

	int chatSendGraph = LoadGraph("Resource\\playerText.png");

	int chatSelectGraph = LoadGraph("Resource\\text_small.png");
};