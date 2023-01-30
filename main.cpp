#include "game.h"


void menu()
{
	cout << "|-------------------------------|" << endl;
	cout << "|------1.start-----0.exit-------|" << endl;
	cout << "|-------------------------------|" << endl;
}

void game()
{
	//雷的信息存储
	char mine[ROWS][COLS] = {0};//布置好的雷信息
	char show[ROWS][COLS] = {0};//排查出雷的信息

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');//将要布置雷的数组全初始化0
	InitBoard(show, ROWS, COLS, 'o');//将要排查的雷全初始化*

	//打印棋盘(棋盘多出的一圈是防止下标越界的，不需要打印，所以传ROW COL)
	//DisplayBoard(mine, ROW, COL);//布置好的雷信息,调试完成后应该注释掉
	//DisplayBoard(show, ROW, COL);//排查出雷的信息

	//放雷,第三个参数：雷的个数
	//SetMine(mine,ROW,COL,MINE);//方法1（优化前）
	SetMine2(mine, ROW, COL, EASY_COT);//方法2（优化后）

	DisplayBoard(show, ROW, COL);//排查出雷的信息

	//排雷
	FindMine(mine, show, ROW, COL);
}

//测试函数
void test()
{
	int option;

	srand((unsigned int)time(NULL));//随机数种子

	do
	{
		cout << "请选择" << endl;
		menu();
		cin >> option;

		system("cls");

		switch (option)
		{
		case 1:
			game();
			break;

		case 0:
			cout << "感谢游玩!" << endl;
			Sleep(1000);
			break;

		default:
			cout << "选项有误!" << endl;
			break;
		}
	} while (option);
}

int main()
{
	test();
	return 0;
}