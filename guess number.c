#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Menu() {
	printf("================\n");
	printf(" 1.��ʼ��Ϸ\n");
	printf(" 0.������Ϸ\n");
	printf("================\n");
	printf("please input�� ");
	int chioce = 0;
	scanf("%d", &chioce);
	return chioce;
}

void game() {
	//�����������1-100��
	int guess = rand() % 100 + 1;
	//��ʾ����һ����
	while (1) {
		printf("������һ��������");
		int num = 0;
		scanf("%d", &num);
		//�Ƚϲ������û���ʾ
		if (num < guess) {
			printf("����\n");
		}
		else if (num > guess) {
			printf("����\n");
		}
		else {
			printf("��ϲ�� �¶��ˣ�\n");
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
			printf("������������\n");
		}
	}

	system("pause");
	return 0;
}