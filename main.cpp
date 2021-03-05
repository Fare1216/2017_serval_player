#include "DxLib.h"


typedef enum{
	TitleLeady,
	Title,
	CountLeady,
	Count,
	MainLeady,
	Main,
	SelectLeady,
	Select,
}eScene;


int Scene = TitleLeady;

int i; //����Ԃ��p

int mx;        //�}�E�Xx���W
int my;        //�}�E�Xy���W
int Mouse;     //�}�E�X�ʒu
int cflag = 0; //�N���b�N�̃t���O

int count; //�J��Ԃ���
int one; //��̈�
int ten; //�\�̈�

/*-----�摜�p�ϐ�-----*/
int title;
int back;
int count_back;
int num_back;
int select_back;
int arrow[2];
int num[10];
int start;
int back_count;
int back_main;
int back_title;


void Graph();


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){

	SetGraphMode(640, 360, 32), ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);


	Graph();


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0){


		/*-----�}�E�X���W�@�擾-----*/
		Mouse = GetMouseInput();
		GetMousePoint(&mx, &my);


		switch (Scene){

		case TitleLeady: {

			Scene = Title;
			break;
		}

		case Title: {
			DrawGraph(   0,   0, title, FALSE);

			/*-----Click-----*/
			if (0 <= mx && mx < 640 && 0 <= my && my < 360){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					Scene = CountLeady;
					cflag = 1;
				}
			}
			if (Mouse & MOUSE_INPUT_LEFT){
				cflag = 1;
			}
			else if ((Mouse & MOUSE_INPUT_LEFT) == 0){
				cflag = 0;
			}

			break;
		}

		case CountLeady: {
			count = 0;
			one = 100;
			ten = 100;

			Scene = Count;
			break;
		}

		case Count: {
			DrawGraph(   0,   0, count_back, FALSE);
			DrawGraph( 375, 100, arrow[0], FALSE);
			DrawGraph( 455, 100, arrow[0], FALSE);
			DrawGraph( 375, 145, num_back, FALSE);
			DrawGraph( 455, 145, num_back, FALSE);
			DrawGraph( 375, 230, arrow[1], FALSE);
			DrawGraph( 455, 230, arrow[1], FALSE);
			DrawGraph( 375, 280, start, FALSE);

			DrawGraph( 377, 147, num[ten%10], FALSE);
			DrawGraph( 457, 147, num[one%10], FALSE);

			/*-----�\�̈ʁ@�J�E���g�A�b�v-----*/
			if (375 <= mx && mx < 450 && 100 <= my && my < 135){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					ten++;
					cflag = 1;
				}
			}
			/*-----��̈ʁ@�J�E���g�A�b�v-----*/
			if (455 <= mx && mx < 530 && 100 <= my && my < 135){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					one++;
					cflag = 1;
				}
			}
			/*-----�\�̈ʁ@�J�E���g�_�E��-----*/
			if (375 <= mx && mx < 450 && 230 <= my && my < 265){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					ten--;
					cflag = 1;
				}
			}
			/*-----��̈ʁ@�J�E���g�_�E��-----*/
			if (455 <= mx && mx < 530 && 230 <= my && my < 265){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					one--;
					cflag = 1;
				}
			}
			/*-----Start �N���b�N-----*/
			if (375 <= mx && mx < 530 && 280 <= my && my < 330){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					Scene = MainLeady;
					cflag = 1;
				}
			}
			if (Mouse & MOUSE_INPUT_LEFT){
				cflag = 1;
			}
			else if ((Mouse & MOUSE_INPUT_LEFT) == 0){
				cflag = 0;
			}

			break;
		}

		case MainLeady:{
			count += (ten % 10) * 10;
			count += (one % 10);

			Scene = Main;
			break;
		}

		case Main: {

			for (i = 0; i < count; i++){
				switch (GetRand(9)){
				case 0:PlayMovie("Movie/���΂񂿂���.mpg", 1, DX_MOVIEPLAYTYPE_NORMAL); break;
				case 1:PlayMovie("Movie/�������[�I.mpg", 1, DX_MOVIEPLAYTYPE_NORMAL); break;
				case 2:PlayMovie("Movie/���ׂȂ���I.mpg", 1, DX_MOVIEPLAYTYPE_NORMAL); break;
				case 3:PlayMovie("Movie/�킽���̓T�[�o���I.mpg", 1, DX_MOVIEPLAYTYPE_NORMAL); break;
				default:PlayMovie("Movie/�������[���I.mpg", 1, DX_MOVIEPLAYTYPE_NORMAL); break;
				}
			}

			Scene = SelectLeady;
			break;
		}

		case SelectLeady: {

			Scene = Select;
			break;
		}

		case Select:{
			DrawGraph(   0,   0, select_back, FALSE);
			DrawGraph( 375, 140, back_count, FALSE);
			DrawGraph( 375, 210, back_main, FALSE);
			DrawGraph( 375, 280, back_title, FALSE);

			/*-----�񐔑I���� �N���b�N-----*/
			if (375 <= mx && mx < 530 && 140 <= my && my < 190){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					Scene = CountLeady;
					cflag = 1;
				}
			}
			/*-----�����񐔂� �N���b�N-----*/
			if (375 <= mx && mx < 530 && 210 <= my && my < 260){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					Scene = Main;
					cflag = 1;
				}
			}
			/*-----�^�C�g���� �N���b�N-----*/
			if (375 <= mx && mx < 530 && 280 <= my && my < 330){
				if (Mouse & MOUSE_INPUT_LEFT && cflag == 0){
					Scene = TitleLeady;
					cflag = 1;
				}
			}
			if (Mouse & MOUSE_INPUT_LEFT){
				cflag = 1;
			}
			else if ((Mouse & MOUSE_INPUT_LEFT) == 0){
				cflag = 0;
			}

			break;
		}

		}
		
		
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;

}


void Graph(){
	title       = LoadGraph("Graph/title.png");
	back        = LoadGraph("Graph/back.png");
	count_back  = LoadGraph("Graph/c_back.png");
	num_back    = LoadGraph("Graph/n_back.png");
	select_back = LoadGraph("Graph/s_back.png");
	arrow[0]    = LoadGraph("Graph/up.png");
	arrow[1]    = LoadGraph("Graph/down.png");

	start      = LoadGraph("Graph/st_button.png");
	back_count = LoadGraph("Graph/co_button.png");
	back_main  = LoadGraph("Graph/om_button.png");
	back_title = LoadGraph("Graph/ba_button.png");

	num[0] = LoadGraph("Graph/0.png");
	num[1] = LoadGraph("Graph/1.png");
	num[2] = LoadGraph("Graph/2.png");
	num[3] = LoadGraph("Graph/3.png");
	num[4] = LoadGraph("Graph/4.png");
	num[5] = LoadGraph("Graph/5.png");
	num[6] = LoadGraph("Graph/6.png");
	num[7] = LoadGraph("Graph/7.png");
	num[8] = LoadGraph("Graph/8.png");
	num[9] = LoadGraph("Graph/9.png");
}