#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10

struct monster
{
	char name[10];
	int hp;
	int atk;
	int gold;
};
int monster_list(void)
{
	struct monster m[10];
	int i;

	FILE* f;
	f = fopen("monster_list.txt", "r");

	printf("���� �̸� | ���� ü�� | ���� ���ݷ� | ó���� ȹ�氡���� ��� |\n");

	for (i = 0; i < 10; i++)
	{
		printf("%6s| %6d| %8d| %10d|\n", m[i].name, m[i].hp, m[i].atk, m[i].gold);
	}
	fclose(f);
}

