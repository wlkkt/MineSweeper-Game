#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//�������е��߼�


//ɨ����Ϸ�˵�
void menu()
{
	printf("**********************\n");
	printf("***** 1����ʼ��Ϸ*****\n");
	printf("***** 0��������Ϸ*****\n");
	printf("**********************\n");
}


void game()
{
	char mine[ROWS][COLS];//��Ų��úõ���
	char show[ROWS][COLS];//����Ų�����׵���Ϣ
	//��ʼ������
	//1. mine�����ʼ��ȫ'0'
	//2. show�����ʼ��ȫ'*'
	InitBoard(mine, ROWS, COLS, '0');     //!!!!ע����board����broadע����game.c�ļ��еĺ�������һ�¡�
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//1. ������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//2. �Ų���
	FindMine(mine, show, ROW, COL);
}

//ɨ����Ϸ�����߼�
int main()
{


	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}

	} while (input);

	return 0;
}


