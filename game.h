#pragma once
#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

#define EASY_COT 10 //简单模式（模式选择？）

#define MINE 9//雷

#define ROW 9//棋盘行
#define COL 9//列

#define ROWS ROW+2//棋盘外圈行
#define COLS COL+2//棋盘外圈列

//初始化棋盘(为了保证初始化成不同的字符，加了set参数)
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);

//打印棋盘（布置好雷的信息）
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//放雷（优化前）
void SetMine(char board[ROWS][COLS], int row, int col,int mine);
//放雷(优化后)
void SetMine2(char board[ROWS][COLS], int row, int col, int mine);

//排雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
