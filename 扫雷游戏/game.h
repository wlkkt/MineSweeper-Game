#pragma once

//要包含的头文件 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//数据定义
#define EASY_COUNT 10            //设定要布置雷的个数
#define ROW 9					 //设定行的值
#define COL 9					 //设定列的值
#define ROWS ROW+2				 //ROWS = ROW + 2
#define COLS COL+2				 //COLS = COL + 2

//函数声明


//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);