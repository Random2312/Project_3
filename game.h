#pragma once
#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

#define EASY_COT 10 //��ģʽ��ģʽѡ�񣿣�

#define MINE 9//��

#define ROW 9//������
#define COL 9//��

#define ROWS ROW+2//������Ȧ��
#define COLS COL+2//������Ȧ��

//��ʼ������(Ϊ�˱�֤��ʼ���ɲ�ͬ���ַ�������set����)
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);

//��ӡ���̣����ú��׵���Ϣ��
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//���ף��Ż�ǰ��
void SetMine(char board[ROWS][COLS], int row, int col,int mine);
//����(�Ż���)
void SetMine2(char board[ROWS][COLS], int row, int col, int mine);

//����
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
