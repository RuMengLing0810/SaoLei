#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"

void InitBoard(char board[ROWS][COLS], int r, int c, char set)//初始化棋盘
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}	
}
void DisplayBoard(char board[ROWS][COLS], int r, int c)//展示化棋盘
{
	printf("-#-#-#-#-#-#-#-#-#-#-#-#-");
	printf("\n");
	for (int i = 0; i < ROW + 1; i++)
	{
		
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 0; i < ROW; i++)
	{
		printf("%d ", i + 1);
		for (int j = 0; j < COL; j++)
		{

			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}

void SetMine(char Mine[ROWS][COLS], int x, int y)//随机布置雷
{
	int count = QuntityMine;
	do
	{
		int a = rand() % x + 1;
		int b = rand() % y + 1;
		if (Mine[a][b] == '0')//0的ASCII码是48
		{
			Mine[a][b] = '1';
			count--;
		}
	} while (count);
}

int GetMineCount(char Mine[ROWS][COLS], int x, int y)
{
	return  Mine[x - 1][y] + Mine[x + 1][y] + Mine[x][y - 1] + Mine[x][y + 1] + Mine[x - 1][y - 1] + Mine[x + 1][y + 1] + Mine[x + 1][y - 1] + Mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char Mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < r * c - QuntityMine)
	{
		printf("请输入要排查的坐标\n示例: 1 3\n ");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)//坐标合法性判断
		{
			if (Mine[x][y] == '1')
			{
				printf("💥 游戏结束，你踩到雷了！\n\n");
				DisplayBoard(Mine, r, c);
				system("pause"); // 暂停查看成果
				break;
			}
			else
			{
				if (show[x][y] == '*')
				{
					int count = GetMineCount(Mine, x, y);
					show[x][y] = count + '0';
					system("cls");   // 清空屏幕（Windows）
					printf("当前棋盘：\n");
					DisplayBoard(show, r, c);
					printf("\n");
					win++;
				}
				else
				{
					printf("该坐标已经被排查\n");
				}
			}
		}
		else
		{
			printf("坐标输入错误\n");
		}
	}
	if (win == r * c - QuntityMine)
	{
		printf("挑战成功,游戏结束\n");
		DisplayBoard(Mine, r, c);
	}
}