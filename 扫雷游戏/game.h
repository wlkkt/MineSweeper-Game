#pragma once

//Ҫ������ͷ�ļ� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//���ݶ���
#define EASY_COUNT 10            //�趨Ҫ�����׵ĸ���
#define ROW 9					 //�趨�е�ֵ
#define COL 9					 //�趨�е�ֵ
#define ROWS ROW+2				 //ROWS = ROW + 2
#define COLS COL+2				 //COLS = COL + 2

//��������


//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//������
void SetMine(char board[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);