#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

Menu() {
	printf("=====================\n");
	printf("1.start game！ \n");
	printf("0.leave！ \n");
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
	//对于show map,需要都设为*
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			show_map[row][col] = '*';
		}
	}
	//2.对于minemap，需要随机生成若干地雷
	//使用0表示不是地雷，1表示是地雷
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col) {
			mine_map[row][col] = '0';//此处用数字0也可以
		}
	}
	int n = MINE_COUNT;
	srand((unsigned int)time(0));
	while (n > 0) {
		//s生成随机坐标
		 int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col] == '1') {
			//该位置已经是地雷了
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
	//在打印其他行
	for (int col = 0; col < MAX_COL - 2; ++col) {
		printf("---");
	}
	printf("\n");
	for (int row = 0; row < MAX_ROW; ++row) {
		printf("  %d|",row);
		//打印本行的而每一列
		for (int col = 0; col < MAX_COL; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void Updateshowmap(int row,int col,
	char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]) {
	//检测周围8个格子的状态
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
	//得到周围8个格子地雷数
	//假设count为2，实际上希望看到的内容是字符2
	show_map[row][col] = '0' + count;
}

void Game() {
	//1.create map,创建地图
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];

	//已经被翻开的空格数
	int blank_count_already_show = 0;

	Init(show_map, mine_map); 
		//2,打印棋盘

	while (1) {
		
		Printmap(show_map);
		//todo 为了调试使用！最终需要删掉
		//printf("\n");
		//Printmap(mine_map);
		
		printf("please input an address(row col): ");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//在这里清屏，清掉之前打印的
		system("cls");

		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL) {
			printf("input error!please try again!\n");
			continue;
		}
		if (show_map[row][col] != '*') {
			printf("input be occupied！ \n");
			continue;
		}
		//判定是否有地雷
		if (mine_map[row][col] == '1') {
			printf("game over!\n");
			Printmap(mine_map);
			break;
		}
		//5.判断游戏是否胜利
		//判定所有非地雷都被翻开（）
		++blank_count_already_show;
		if (blank_count_already_show == MAX_COL * MAX_ROW - MINE_COUNT) {
			
			printf("you are win!\n");
			Printmap(mine_map);
			break;

		}
		//6.统计当前翻开周围雷个数
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