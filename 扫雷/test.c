#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void menu()
{
	printf("****************************\n");
	printf("---------- 0.exit ----------\n");
	printf("---------- 1.play ----------\n");
	printf("****************************\n");
}

void game()
{

}

void test()
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
			printf("���̽���������Ϊ0\n");
			break;
		default:
			printf("�������ڿ����У��´��ٳ��԰ɣ�\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}