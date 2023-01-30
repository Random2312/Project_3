#include "game.h"


void menu()
{
	cout << "|-------------------------------|" << endl;
	cout << "|------1.start-----0.exit-------|" << endl;
	cout << "|-------------------------------|" << endl;
}

void game()
{
	//�׵���Ϣ�洢
	char mine[ROWS][COLS] = {0};//���úõ�����Ϣ
	char show[ROWS][COLS] = {0};//�Ų���׵���Ϣ

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');//��Ҫ�����׵�����ȫ��ʼ��0
	InitBoard(show, ROWS, COLS, 'o');//��Ҫ�Ų����ȫ��ʼ��*

	//��ӡ����(���̶����һȦ�Ƿ�ֹ�±�Խ��ģ�����Ҫ��ӡ�����Դ�ROW COL)
	//DisplayBoard(mine, ROW, COL);//���úõ�����Ϣ,������ɺ�Ӧ��ע�͵�
	//DisplayBoard(show, ROW, COL);//�Ų���׵���Ϣ

	//����,�������������׵ĸ���
	//SetMine(mine,ROW,COL,MINE);//����1���Ż�ǰ��
	SetMine2(mine, ROW, COL, EASY_COT);//����2���Ż���

	DisplayBoard(show, ROW, COL);//�Ų���׵���Ϣ

	//����
	FindMine(mine, show, ROW, COL);
}

//���Ժ���
void test()
{
	int option;

	srand((unsigned int)time(NULL));//���������

	do
	{
		cout << "��ѡ��" << endl;
		menu();
		cin >> option;

		system("cls");

		switch (option)
		{
		case 1:
			game();
			break;

		case 0:
			cout << "��л����!" << endl;
			Sleep(1000);
			break;

		default:
			cout << "ѡ������!" << endl;
			break;
		}
	} while (option);
}

int main()
{
	test();
	return 0;
}