#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>


#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10

void startscreen();

struct monster
{
	char name[10];
	int hp;
	int atk;
	int gold;
	int lock;
}m[10];

int monster_list(void)
{
	system("cls");
	
	int i;
	int num = 0;
	FILE* fp;

	fopen_s(&fp, "monster_list.txt", "r");  //player status �ҷ�����




	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%s %d %d %d %d", &m[i].name, &m[i].hp, &m[i].atk, &m[i].gold,&m[i].lock);
	
	}
	fclose(fp);
	printf("���� �̸� | ���� ü�� | ���� ���ݷ� | ó���� ȹ�氡���� ��� |\n");

	
	for (i = 0; i < 10; i++)
	{
		if (m[i].lock == 1) 
		{
			printf("%12s| %12d| %14d| %23d|\n", m[i].name, m[i].hp, m[i].atk, m[i].gold);
		}
		else 
		{
			printf("%12s| %12s| %14s| %23s|\n", "????","??" , "?", "??");
		}
	}

	printf("1.����ȭ������ ���ư��� 2. ���� �ʱ�ȭ\n");
	scanf("%d", &num);
	if (num == 1) {
		system("cls");
		startscreen();
		
	}
	else {

		fopen_s(&fp, "monster_list.txt", "r");  //

		for (int i = 0; i < StatusSize; i++)
		{
			fscanf(fp, "%s %d %d %d %d", &m[i].name, &m[i].hp, &m[i].atk, &m[i].gold, &m[i].lock);

		}
		fclose(fp);

		fopen_s(&fp, "monster_list.txt", "w");

		for (int i = 0; i < StatusSize; i++) {
			int lockoff = 0;
			fprintf(fp, "%s %d %d %d %d \n", m[i].name, m[i].hp, m[i].atk, m[i].gold, lockoff); //���� �ʱ�ȭ


		}
		fclose(fp);

		system("cls");
		monster_list();
	}
}

