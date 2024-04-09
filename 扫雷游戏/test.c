#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//程序运行的逻辑


//扫雷游戏菜单
void menu()
{
	printf("**********************\n");
	printf("***** 1、开始游戏*****\n");
	printf("***** 0、结束游戏*****\n");
	printf("**********************\n");
}


void game()
{
	char mine[ROWS][COLS];//存放布置好的雷
	char show[ROWS][COLS];//存放排查出的雷的信息
	//初始化棋盘
	//1. mine数组最开始是全'0'
	//2. show数组最开始是全'*'
	InitBoard(mine, ROWS, COLS, '0');     //!!!!注意是board不是broad注意与game.c文件中的函数名的一致。
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//1. 布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//2. 排查雷
	FindMine(mine, show, ROW, COL);
}

//扫雷游戏主体逻辑
int main()
{


	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("选择错误，重新选择\n");
			break;
		}

	} while (input);

	return 0;
}


