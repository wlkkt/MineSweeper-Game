#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//对geme()中提到的所有函数的具体实现


//定义棋盘函数(board是作为形参的一个新数组名但是里面的行名和列名不变1)
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//（mine/show数组名，  ROWS,  COLS,  字符'0'/'*'）
{
	int i = 0;
	for (int i = 0; i < rows; i++)       //确定打印的行数
	{
		for (int j = 0; j < cols; j++)  //确定打印的列数
		{
			board[i][j] = set;          //根据要打印的行数和列数存储棋盘所要的字符
		}
	}
}

//打印棋盘函数
void DisplayBoard(char board[ROWS][COLS], int row, int col) //（show , ROW ,COL）
{
	int i = 0;
	printf("--------扫雷游戏--------\n");
	for (i = 0; i <= col; i++)     //根据上面要求的列数打印行标0 1 2 3 4 5 6 ...
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)     //根据上面要求的行数打印列标1 2 3 4 5 6 ...
	{
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)//打印行标的同时在该行同时打印设定的字符
		{
			printf("%c ", board[i][j]); //%c打印字符，board[i][j]数组已经在InitBoard函数中储存过了，现在许需要的是将存储的东西在命令提示符中打印出来
		}
		printf("\n");
	}
}


//布置雷函数
void SetMine(char board[ROWS][COLS], int row, int col) //(mine, ROW , COL)
{
	//布置10个雷
	//⽣成随机的坐标，布置雷
	int count = EASY_COUNT;           //在头文件中设定要布置的雷的个数
	while (count)
	{
		int x = rand() % row + 1;     //根据行数和rand伪随机函数生成雷对应的行坐标x
		int y = rand() % col + 1;	  //根据列数和rand伪随机函数生成雷对应的列坐标y
		if (board[x][y] == '0')		  //因为开始引入的数组是全部为字符'0'的mine数组所以board[x][y]中的值肯定全为'0'
		{
			board[x][y] = '1';		  //开始布置雷，这里规定雷的是字符'1';
			count--;				  //每布置一个雷就减少一个要布置的雷的个数count
		}
	}
}




//返回排查位置周围八个位置的存储字符函数（本函数由于没有在game.h中添加，只是想让他在下面使用）
int GetMineCount(char mine[ROWS][COLS], int x, int y)  //（mine ，x ，y）get因为这个函数是                    //在find函数中嵌套的所以传入的是x ，y而非之前的那些col、row之类的
{
	return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0');



	//排查的位置为x，y
	//'1'-'0' = 49 - 48 = 1
	//x-1,y-1  x-1,y  x-1,y+1
	//x,y-1    x,y    x,y+1
	//x+1,y-1  x+1,y  x+1,y+1
}


//排查函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) //(mine,show,ROW,COL)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)    //一共有10个雷，如果win值大于等于9*9-10=71时，证明此时雷已经被排完，进行下面的if
	{
		printf("请输入要排查的坐标:>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)  //只有在x，y的值满足要求时才会进行排查
		{
			if (mine[x][y] == '1')      //如果该位置是雷，那么被炸死游戏结束
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, ROW, COL);     //被炸死后利用棋盘打印函数显示所有雷的位置
				break;
			}
			else
			{
				//该位置不是雷，就利用getmine函数统计这个坐标周围有⼏个雷
				int count = GetMineCount(mine, x, y);    //用整型count来接收get统计的周围雷的个数
				show[x][y] = count + '0';                //如有疑问，请跳转至注释一
				DisplayBoard(show, ROW, COL);            //将show[x][y]得到的字符型传递给打印棋盘函数从而显示排查位置周围雷的个数。
				win++;                //每排除一个雷我们的胜算就加一分，即win++
			}
		}
		else                                           //x，y的值不满足要求，请重新输入
		{
			printf("坐标非法，重新输⼊\n");
		}
	}
	if (win == row * col - EASY_COUNT)     //当win=71时，游戏胜利排除所有雷
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);       //展示答案：最后打印所有雷
	}
}