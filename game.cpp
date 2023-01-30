#include "game.h"

//��ʼ������
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

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	cout << "|----------ɨ����Ϸ----------|" << endl;
	
	//��ӡ�к�
	cout << " ";
	for (int i = 0; i <=col; i++)
	{
		cout <<i <<"  ";
	}

	cout << endl ;
	cout << " |---------------------------|" << endl;

	for (int i = 1; i <= row; i++)
	{
		//��ӡ�к�
		cout << i<<"|";
		for (int j = 1; j <= col; j++)
		{
			cout <<"  " << board[i][j];
		}
		cout << endl;
	}
	cout << " |---------------------------|" << endl;
}

//����(��һ�ַ���)�����Ż������ܳ����ظ���ֵ�������
void SetMine(char board[ROWS][COLS], int row, int col, int mine)
{
	int r, c;
	//�׵ĸ���
	for (int i = 0; i < mine; i++)
	{
		//����1-9�������,��Ϊ����Ȧ�Ƿ�ֹ����Խ��ģ����ø�ֵ
		r = rand() % row + 1;
		c = rand() % col + 1;
		//�׵�λ��
		board[r][c] = '+';
	}
}

//����(�ڶ��ַ���)���Ż���
void SetMine2(char board[ROWS][COLS], int row, int col, int mine)
{
	while (mine)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')//��λ���ǿգ�����
		{
			board[x][y] = '+';
			mine--;
		}
	}
}

//���������Χ�м�����,���ظ��±���Χ�׵ĸ���
static int get_mine_count(char mine[ROWS][COLS], int x, int y)//���ڴ��ļ�ʹ��
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

//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win=0;

	while (win<ROW*COL-EASY_COT)
	{
		cout << "�����Ų������(x,y)��>";

		cin >> x >> y;//x��yȡֵ��Χ1-9
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '+')
			{
				system("cls");
				cout << "�㱻ը���ˣ�" << endl;
				
				DisplayBoard(mine, row, col);//��������
				break;
			}
			else//�����ף�ͳ�Ƹ�������Χ�м�����
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';//����ת�ַ�

				system("cls");
				DisplayBoard(show, ROW, COL);//�Ų���׵���Ϣ

				win++;
			}
		}
		else
		{
			cout << "������ķ�Χ���Ϸ������������룺" << endl;
		}
	}

	if (win == ROW * COL - EASY_COT)
	{
		cout << "��ϲ��ʤ��";
	}
}

