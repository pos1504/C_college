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

	fopen_s(&fp, "monster_list.txt", "r");  //player status 불러오기




	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%s %d %d %d %d", &m[i].name, &m[i].hp, &m[i].atk, &m[i].gold,&m[i].lock);
	
	}
	fclose(fp);
	printf("몬스터 이름 | 몬스터 체력 | 몬스터 공격력 | 처리시 획득가능한 골드 |\n");

	
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

	printf("1.메인화면으로 돌아가기\n");
	scanf("%d", &num);
	if (num == 1) {
		system("cls");
		startscreen();
		
	}
}

