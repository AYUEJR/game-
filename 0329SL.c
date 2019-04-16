#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

Menu() {
	printf("=====================\n");
	printf("1.start game�� \n");
	printf("0.leave�� \n");
	printf("=====================\n");
	printf("please input your chioce: ");
	int chioce = 0;
	scanf("%d", &chioce);
	return chioce;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char show_map[MAX_ROW][MAX_COL], char mine_map[MAX_ROW][MAX_COL]) {
	//����show map,��Ҫ����Ϊ*
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	//2.����minemap����Ҫ����������ɵ���
	//ʹ��0��ʾ���ǵ��ף�1��ʾ�ǵ���
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			mine_map[row][col] = '0';//�˴�������0Ҳ����
		}
	}
	int n = MINE_COUNT;
	srand((unsigned int)time(0));
	while (n > 0) {
		//s�����������
		 int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			//��λ���Ѿ��ǵ�����
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
	
}




void Printmap(char map[MAX_ROW][MAX_COL]) {
	//todo
	printf("   |");
	for (int i = 0; i < MAX_COL; ++i) {
		printf("%d ", i);
	}
	printf("\n");
	//�ڴ�ӡ������
	for (int col = 0; col < MAX_COL - 2; ++col) {
		printf("---");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; ++row) {
		printf("  %d|",row);
		//��ӡ���еĶ�ÿһ��
		for (int col = 0; col < MAX_COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void Updateshowmap(int row,int col,
	char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	//�����Χ8�����ӵ�״̬
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 && row - 1 < MAX_ROW && col - 1 < MAX_COL,
		mine_map[row - 1][col - 1] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col >= 0 && row - 1 < MAX_ROW && col < MAX_COL,
		mine_map[row - 1][col] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col + 1 >= 0 && row - 1 < MAX_ROW && col + 1 < MAX_COL,
		mine_map[row - 1][col +1] == '1') {
		++count;
	}
	if (row >= 0 && col - 1 >= 0 && row  < MAX_ROW && col - 1 < MAX_COL,
		mine_map[row ][col - 1] == '1') {
		++count;	
	}
	if (row >= 0 && col + 1 >= 0 && row < MAX_ROW && col +1 < MAX_COL,
		mine_map[row][col + 1] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col - 1 >= 0 && row + 1 < MAX_ROW && col - 1 < MAX_COL,
		mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col >= 0 && row + 1 < MAX_ROW && col  < MAX_COL,
		mine_map[row + 1][col] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col +1 >= 0 && row + 1 < MAX_ROW && col + 1 < MAX_COL,
		mine_map[row + 1][col + 1] == '1') {
		++count;
	}
	//�õ���Χ8�����ӵ�����
	//����countΪ2��ʵ����ϣ���������������ַ�2
	show_map[row][col] = '0' + count;
}

void Game() {
	//1.create map,������ͼ
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];

	//�Ѿ��������Ŀո���
	int blank_count_already_show = 0;

	Init(show_map, mine_map); 
		//2,��ӡ����

	while (1) {
		
		Printmap(show_map);
		//todo Ϊ�˵���ʹ�ã�������Ҫɾ��
		//printf("\n");
		//Printmap(mine_map);
		
		printf("please input an address(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//���������������֮ǰ��ӡ��
		system("cls");

		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("input error!please try again!\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("input be occupied�� \n");
			continue;
		}
		//�ж��Ƿ��е���
		if (mine_map[row][col] == '1') {
			printf("game over!\n");
			Printmap(mine_map);
			break;
		}
		//5.�ж���Ϸ�Ƿ�ʤ��
		//�ж����зǵ��׶�����������
		++blank_count_already_show;
		if (blank_count_already_show == MAX_COL * MAX_ROW - MINE_COUNT) {
			
			printf("you are win!\n");
			Printmap(mine_map);
			break;

		}
		//6.ͳ�Ƶ�ǰ������Χ�׸���
		Updateshowmap(row,col,show_map,mine_map);
	}

}
	

int main() {
	while (1) {
		int chioce = Menu();
		if (chioce == 1) {
			Game();
		}
		else if (chioce == 0) {
			printf("good bye!\n");
		}
		else {
			printf("input error!\n");
		}
	}

	system("pause");
	return 0;
}