#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu() {
	printf("================\n");
	printf(" 1.开始游戏\n");
	printf(" 0.结束游戏\n");
	printf("================\n");
	printf("please input： ");
	int chioce = 0;
	scanf("%d", &chioce);
	return chioce;
}

void game() {
	//生成随机数（1-100）
	int guess = rand() % 100 + 1;
	//提示输入一个数
	while (1) {
		printf("请输入一个整数：");
		int num = 0;
		scanf("%d", &num);
		//比较并反馈用户提示
		if (num < guess) {
			printf("低了\n");
		}
		else if (num > guess) {
			printf("高了\n");
		}
		else {
			printf("恭喜你 猜对了！\n");
			return;
		}

	}
}

int main() {
	srand(time(0));
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			game();
		}
		else if (choice == 0) {
			printf("good bye!\n");
				break;
		}
		else {
			printf("您的输入有误！\n");
		}
	}

	system("pause");
	return 0;
}