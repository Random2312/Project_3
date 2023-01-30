#include "game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	cout << "|----------扫雷游戏----------|" << endl;
	
	//打印列号
	cout << " ";
	for (int i = 0; i <=col; i++)
	{
		cout <<i <<"  ";
	}

	cout << endl ;
	cout << " |---------------------------|" << endl;

	for (int i = 1; i <= row; i++)
	{
		//打印行号
		cout << i<<"|";
		for (int j = 1; j <= col; j++)
		{
			cout <<"  " << board[i][j];
		}
		cout << endl;
	}
	cout << " |---------------------------|" << endl;
}

//放雷(第一种方法)（待优化，可能出现重复赋值的情况）
void SetMine(char board[ROWS][COLS], int row, int col, int mine)
{
	int r, c;
	//雷的个数
	for (int i = 0; i < mine; i++)
	{
		//产生1-9的随机数,因为最外圈是防止数组越界的，不用赋值
		r = rand() % row + 1;
		c = rand() % col + 1;
		//雷的位置
		board[r][c] = '+';
	}
}

//放雷(第二种方法)（优化后）
void SetMine2(char board[ROWS][COLS], int row, int col, int mine)
{
	while (mine)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')//该位置是空，放雷
		{
			board[x][y] = '+';
			mine--;
		}
	}
}

//检查坐标周围有几个雷,返回该下标周围雷的个数
static int get_mine_count(char mine[ROWS][COLS], int x, int y)//仅在此文件使用
{
	int count = 0;

	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (mine[i][j] == '+')
			{
				count++;
			}
		}
	}
	return count;
}

//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win=0;

	while (win<ROW*COL-EASY_COT)
	{
		cout << "输入排查的坐标(x,y)：>";

		cin >> x >> y;//x，y取值范围1-9
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '+')
			{
				system("cls");
				cout << "你被炸死了！" << endl;
				
				DisplayBoard(mine, row, col);//死个明白
				break;
			}
			else//不是雷，统计该坐标周围有几个雷
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//整型转字符

				system("cls");
				DisplayBoard(show, ROW, COL);//排查出雷的信息

				win++;
			}
		}
		else
		{
			cout << "你输入的范围不合法！请重新输入：" << endl;
		}
	}

	if (win == ROW * COL - EASY_COT)
	{
		cout << "恭喜获胜！";
	}
}

