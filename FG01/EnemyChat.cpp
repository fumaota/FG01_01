#include "EnemyChat.h"

EnemyChat::EnemyChat() {}
EnemyChat::~EnemyChat(){}

void EnemyChat::Initialize() {
	enemyPosX[0] = 20;        enemyPosX[1] = 20;
	enemyPosY[0] = 90;        enemyPosY[1] = 190;
	
	enemyPosX[2] = 20;        enemyPosX[3] = 20;
	enemyPosY[2] = 290;       enemyPosY[3] = 390;

	enemyPosX[4] = 20;        enemyPosX[5] = 20;
	enemyPosY[4] = 490;       enemyPosY[5] = 590;

	enemyPosX[6] = 20;        enemyPosX[7] = 20;
	enemyPosY[6] = 440;       enemyPosY[7] = 490; 

	chatReceponCount = 0;

	chatReceponFlag[0] = TRUE;

    for (int i = 1; i < 10; i++) {
        chatReceponFlag[i] = FALSE;
    }

	ChatScrollY = 0;

    chatchose = 0;

    chatReceponCount = 0;

    chatChoseFlage = 0;
}

void EnemyChat::Update(char* keys, char* oldkeys) {
   /* if (keys[KEY_INPUT_DOWN]) {
        ChatScrollY -= 5;
    }

    if (keys[KEY_INPUT_UP]) {
        ChatScrollY += 5;
    }*/

    /*if (ChatScrollY >= 0) {
        ChatScrollY = 0;
    }*/

    if (keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE) {
        chatchose = 1;
    }

    if (keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE) {
        chatchose = 2;
    }

    if (keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE) {
        chatchose = 3;
    }

    if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE) {
        chatchose = 4;
    }

    if (chatSendFlag[0] == TRUE) {
        chatReceponFlag[1] = TRUE;
    }

    if (chatSendFlag[1] == TRUE) {
        chatReceponFlag[2] = TRUE;
    }

    if (chatSendFlag[2] == TRUE) {
        chatReceponFlag[3] = TRUE;
    }

    if (chatSendFlag[3] == TRUE) {
        chatReceponFlag[4] = TRUE;
    }

    if (chatSendFlag[4] == TRUE) {
        chatReceponFlag[5] = TRUE;
    }

    if (chatReceponCount == 0) {
        chatAnser = 1;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe,DX_PLAYTYPE_BACK,FALSE);
            chatReceponFlag[1] = TRUE;
            chatChoseFlage = 1;
            chatReceponCount += 1;
        }
    }

    if (chatReceponCount == 1) {
        chatAnser = 3;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[2] = TRUE;
            chatChoseFlage = 2;
            chatReceponCount += 1;
        }
    }

    if (chatReceponCount == 2) {
        chatAnser = 2;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[3] = TRUE;
            chatChoseFlage = 3;
            chatReceponCount += 1;
        }
    }

    if (chatReceponCount == 3) {
        chatAnser = 3;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[4] = TRUE;
            chatChoseFlage = 4;
            chatReceponCount += 1;

            ChatScrollY -= 50;
        }
    }

    if (chatReceponCount == 4) {
        chatAnser = 4;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[4] = TRUE;
            chatChoseFlage = 5;
            chatReceponCount += 1;

            ChatScrollY -= 50;
        }
    }
}

void EnemyChat::Draw() {

	    if (chatReceponFlag[0] == TRUE) {
			DrawGraph(enemyPosX[0], enemyPosY[0] + ChatScrollY, chatReceponGraph, TRUE);
			DrawFormatString(enemyPosX[0] + 50, enemyPosY[0] + 50 + ChatScrollY, GetColor(0, 0, 0), "���͂悤");
	    }
		
		
		if (chatReceponFlag[1] == TRUE) {
			DrawGraph(enemyPosX[1], enemyPosY[1] + ChatScrollY, chatReceponGraph, TRUE);
            DrawFormatString(enemyPosX[1] + 50, enemyPosY[1] + 50 + ChatScrollY, GetColor(0, 0, 0), "�Q�V���������");
		}
		
		if (chatReceponFlag[2] == TRUE) {
			DrawGraph(enemyPosX[2], enemyPosY[2] + ChatScrollY, chatReceponGraph, TRUE);
            DrawFormatString(enemyPosX[2] + 50, enemyPosY[2] + 50 + ChatScrollY, GetColor(0, 0, 0), "�����x��������");
		}

		if (chatReceponFlag[3] == TRUE) {
			DrawGraph(enemyPosX[3], enemyPosY[3] + ChatScrollY, chatReceponGraph, TRUE);
            DrawFormatString(enemyPosX[3] + 50, enemyPosY[3] + 50 + ChatScrollY, GetColor(0, 0, 0), "�߂�ǂ�������`");
		}

        if (chatReceponFlag[4] == TRUE) {
            DrawGraph(enemyPosX[4], enemyPosY[4] + ChatScrollY, chatReceponGraph, TRUE);
            DrawFormatString(enemyPosX[4] + 50, enemyPosY[4] + 50 + ChatScrollY, GetColor(0, 0, 0), "����Ȃɋx�񂶂�\n���߁H");
        }

       /* if (chatReceponFlag[5] == TRUE) {
            DrawGraph(enemyPosX[5], enemyPosY[5] + ChatScrollY, chatReceponGraph, TRUE);
            DrawFormatString(enemyPosX[5] + 50, enemyPosY[5] + 50 + ChatScrollY, GetColor(0, 0, 0), "���͂悤");
        }*/

        if (chatChoseFlage == 0) {
            DrawFormatString(68, 650, GetColor(0, 0, 0), "���͂悤");
            DrawFormatString(350, 650, GetColor(0, 0, 0), "����͂�");
            DrawFormatString(68, 750, GetColor(0, 0, 0), "���₷��");
            DrawFormatString(350, 750, GetColor(0, 0, 0), "���肪�Ƃ�");
        }
      
        if (chatChoseFlage == 1) {
            DrawFormatString(68, 650, GetColor(0, 0, 0), "���₷�݁`");
            DrawFormatString(350, 650, GetColor(0, 0, 0), "��������");
            DrawFormatString(68, 750, GetColor(0, 0, 0), "�͂₭����!");
            DrawFormatString(350, 750, GetColor(0, 0, 0), "�͂��₱��!");
        }

        if (chatChoseFlage == 2) {
            DrawFormatString(68, 650, GetColor(0, 0, 0), "��������΁H");
            DrawFormatString(350, 650, GetColor(0, 0, 0), "����!");
            DrawFormatString(68, 750, GetColor(0, 0, 0), "ok!");
            DrawFormatString(350, 750, GetColor(0, 0, 0), "���������܂�");
        }

        if (chatChoseFlage == 3) {
            DrawFormatString(68, 650, GetColor(0, 0, 0), "���͂悤!");
            DrawFormatString(350, 650, GetColor(0, 0, 0), "�₵��");
            DrawFormatString(68, 750, GetColor(0, 0, 0), "�܂��Ԃɍ�����");
            DrawFormatString(350, 750, GetColor(0, 0, 0), "���₷�݁`");
        }

        if (chatChoseFlage == 4) {
            DrawFormatString(68, 650, GetColor(0, 0, 0), "���₷�݁`");
            DrawFormatString(350, 650, GetColor(0, 0, 0), "������������");
            DrawFormatString(68, 750, GetColor(0, 0, 0), "ok!");
            DrawFormatString(350, 750, GetColor(0, 0, 0), "��΂���!");
        }
		//DrawFormatString(100,100,GetColor(255,255,255),"flag = %d",chatReceponFlag1);

}