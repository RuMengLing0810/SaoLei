#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "game.h"
void menu()//菜单
{
	printf("****************************\n");
	printf("---------- 0.exit ----------\n");
	printf("---------- 1.play ----------\n");
	printf("****************************\n");
}

void game()
{
	char Mine[ROWS][COLS];//数组初始化
	char show[ROWS][COLS];
	InitBoard(Mine, ROWS, COLS, '0');//初始化棋盘//雷的信息布置在这个数组里
	InitBoard(show, ROWS, COLS, '*');//排查出雷的信息存在这里
	DisplayBoard(show, ROW, COL);
	SetMine(Mine, ROW, COL);//随机生成雷区
	FindMine(Mine, show, ROW, COL);//排查雷
}
void test()//游戏开始界面
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("进程结束，代码为0\n");
			break;
		default:
			printf("功能正在开发中，下次再尝试吧！\n");
			break;
		}
	} while (input);
}

int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}