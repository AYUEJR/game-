//ʵ��һ��ͨѶ¼���������ϵ����Ϣ�Ĵ���
//��ɾ�Ĳ�
//1.����
//2.ɾ��
//3.�޸ļ�¼
//4.���Ҽ�¼
//5.��ӡȫ��
//6.�����¼
//7.���ȫ��
//����
//1.����������Ϣ���������������ṹ�壩
//2.��Ҫ����ܶ����ݣ�����Ҫ���ݽṹ�����ݽṹ��

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
	printf("1.������ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ӡȫ����ϵ��\n");
	printf("6.������ϵ��\n");
	printf("7.�����ϵ��\n");
	printf("0.�˳�\n");
	printf("=======================\n");
	printf("����������ѡ�� ");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


void Empty() {

}

void Addpersoninfo() {
	printf("������ϵ��\n");
	if (g_address_book.size>=MAX_PERSON_INF0_SIZE){
		printf("���ʧ�ܣ�\n");
		return;
	}
	printf("��������ϵ������:");
	//������һ��ָ��
	Personinfo* person_info = &g_address_book.persons[g_address_book.size];
		scanf("%s", person_info->name);
		printf("��������ϵ�˵绰:");
		scanf("%s", person_info->phone);
		++g_address_book.size;
	printf("�������\n");
}

void Delpersoninfo() {
	printf("ɾ����ϵ��\n");
	if (g_address_book.size<=0){
		printf("ɾ��ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("������Ҫɾ������ϵ�����:  ");
	int id = 0;
	scanf("%d", &id);
	if (id<0||id>=g_address_book.size){
		printf("ɾ��ʧ�ܣ�������������\n");
		return;
	}
	g_address_book.persons[id] = g_address_book.persons[g_address_book.size];
	--g_address_book.size;
	printf("ɾ����ϵ�˳ɹ���\n");
}	

void Findpersoninfo() {
	printf("������ϵ�ˣ�\n");
	//������������
	printf("������Ҫ���ҵ�������");
		char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < g_address_book.size; ++i) {
		Personinfo* info = &g_address_book.persons[i];
		if (strcmp(info->name,name)==0){
			printf("[%d] % s\t%s\n",i,info->name,info->phone);
		}

	}

	printf("������ϵ�˳ɹ�\n");
}

void Updatepersoninfo() {
	printf("������ϵ��\n");
	if (g_address_book.size <= 0) {
		printf("�޸�ʧ��!ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫ�޸ĵ���ţ�");
	int id =0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size) {
		printf("�޸�ʧ�ܣ���������������\n");
		return;
	}
	Personinfo* info = &g_address_book.persons[id];
	printf("�������µ�������(%s)\n",info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(info->name, name);
	}
	printf("�������µĵ绰��(%s)\n",info->phone);
	char phone[1024] = { 0 };
	scanf("%s",phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(info->phone, phone);
	}
	
    printf("������ϵ�˳ɹ���\n");
}

void Printall() {
	printf("��ӡȫ����ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i) {
		Personinfo* info = &g_address_book.persons[i];
		printf("[%d]%s\t%s\n", i, info->name, info->phone);
	}
	printf("�ɹ���ӡ�� %d ����Ϣ��\n", g_address_book.size);
}

void Sortpersoninfo() {
	printf("������ϵ�ˣ�\n");
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
	printf("������ϵ����ɣ�\n");
}
void Clear() {
	printf("���ȫ�����ݣ�\n");
	printf("�����Ҫ���ȫ�������� Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0) {
		g_address_book.size = 0;
		printf("���ȫ�����ݣ�\n");
	}
	else {
		printf("������ݲ���ȡ����\n");
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
		printf("��������������������\n ");
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