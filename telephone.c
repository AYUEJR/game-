//实现一个通讯录程序，完成联系人信息的储存
//增删改查
//1.新增
//2.删除
//3.修改记录
//4.查找记录
//5.打印全部
//6.排序记录
//7.清空全部
//管理
//1.描述基本信息抽象并描述出来（结构体）
//2.需要管理很多数据，就需要数据结构（数据结构）

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Personinfo{
	char name[1024];
	char phone[1024];
}Personinfo;

#define	 MAX_PERSON_INF0_SIZE 300

typedef struct Addressbook {
	Personinfo persons[MAX_PERSON_INF0_SIZE];
	Personinfo temp[MAX_PERSON_INF0_SIZE];
		//[0,size)
		int size;
}Addressbook;

Addressbook g_address_book;

void Init() {	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSON_INF0_SIZE; ++i) {
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0';
	}
}

int Menu() {
	printf("=======================\n");
	printf("1.新增联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.打印全部联系人\n");
	printf("6.排序联系人\n");
	printf("7.清空联系人\n");
	printf("0.退出\n");
	printf("=======================\n");
	printf("请输入您的选择： ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void Empty() {

}

void Addpersoninfo() {
	printf("新增联系人\n");
	if (g_address_book.size>=MAX_PERSON_INF0_SIZE){
		printf("添加失败！\n");
		return;
	}
	printf("请输入联系人姓名:");
	//必须获得一个指针
	Personinfo* person_info = &g_address_book.persons[g_address_book.size];
		scanf("%s", person_info->name);
		printf("请输入联系人电话:");
		scanf("%s", person_info->phone);
		++g_address_book.size;
	printf("新增完成\n");
}

void Delpersoninfo() {
	printf("删除联系人\n");
	if (g_address_book.size<=0){
		printf("删除失败！通讯录为空！\n");
		return;
	}
	printf("请输入要删除的联系人序号:  ");
	int id = 0;
	scanf("%d", &id);
	if (id<0||id>=g_address_book.size){
		printf("删除失败！输入的序号有误！\n");
		return;
	}
	g_address_book.persons[id] = g_address_book.persons[g_address_book.size];
	--g_address_book.size;
	printf("删除联系人成功！\n");
}	

void Findpersoninfo() {
	printf("查找联系人！\n");
	//根据姓名查找
	printf("请输入要查找的姓名：");
		char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < g_address_book.size; ++i) {
		Personinfo* info = &g_address_book.persons[i];
		if (strcmp(info->name,name)==0){
			printf("[%d] % s\t%s\n",i,info->name,info->phone);
		}

	}

	printf("查找联系人成功\n");
}

void Updatepersoninfo() {
	printf("更新联系人\n");
	if (g_address_book.size <= 0) {
		printf("修改失败!通讯录为空\n");
		return;
	}
	printf("请输入要修改的序号：");
	int id =0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("修改失败！您输入的序号有误！\n");
		return;
	}
	Personinfo* info = &g_address_book.persons[id];
	printf("请输入新的姓名：(%s)\n",info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("请输入新的电话：(%s)\n",info->phone);
	char phone[1024] = { 0 };
	scanf("%s",phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	
    printf("更新联系人成功！\n");
}

void Printall() {
	printf("打印全部联系人\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		Personinfo* info = &g_address_book.persons[i];
		printf("[%d]%s\t%s\n", i, info->name, info->phone);
	}
	printf("成功打印了 %d 条信息！\n", g_address_book.size);
}

void Sortpersoninfo() {
	printf("排序联系人！\n");
	//Personinfo* info = &g_address_book.persons[i];
	int i, j;
	for (j = 0; j < g_address_book.size - 1; ++j) {
		for (i = 0; i < g_address_book.size - j - 1; ++i) {
			if (strcmp((g_address_book.persons[i].name), (g_address_book.persons[i + 1].name)) > 0) {
				g_address_book.temp[0] = g_address_book.persons[i];
				g_address_book.persons[i] = g_address_book.persons[i + 1];
				g_address_book.persons[i + 1] = g_address_book.temp[0];
			}
		}
	}
	Printall();
	printf("排序联系人完成！\n");
}
void Clear() {
	printf("清空全部数据！\n");
	printf("您真的要清空全部数据吗？ Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0) {
		g_address_book.size = 0;
		printf("清空全部数据！\n");
	}
	else {
		printf("清空数据操作取消！\n");
	}
}

typedef void(*Func)();



void Init();

int main() {
	Func arr[] = {
		Empty,
		Addpersoninfo,
		Delpersoninfo,
		Findpersoninfo,
		Updatepersoninfo,
		Printall,
		Sortpersoninfo,
		Clear

	};
	
	while (1){
		
		int choice = Menu();
	if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
		printf("您的输入有误，请重新输\n ");
		continue;
	}
	if (choice == 0) {
		printf("goddbye\n");
		break;
	}
	arr[choice]();
 }

	system("pause");
	return 0;
}