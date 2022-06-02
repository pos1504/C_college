#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10

// 100골드를 모으기까지 stage의 수가 적을수록 순위가 높음



void startscreen();

struct Rank
{
	char name[10];
	int stagenum;
	int rank;
}r[5];

int ranking(void)
{
	system("cls");

	int i; int j;
	int num = 0;
	
	FILE* fp;
	fopen_s(&fp, "name.txt", "r");
	
	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%s", &r[i].name);
	}
	fclose(fp);

	int buffer[StatusSize] = { 0 };
	FILE* f = fopen("hero_status.txt", "r");
	fscanf(f, "%d", buffer[9]);
	r[i].stagenum = buffer[9];
	fclose(f);

	printf("순위 | 플레이어 이름 | 스테이지 수 |\n");

	for (i = 0; i < 10; i++)
	{
		r[i].rank = 0;
		for(j=0; j<10; j++)
		{ 
			if (r[i].stagenum > r[j].stagenum )
		    {
				r[i].rank++;
		    }
		}
		printf("%4d| %8d| %16d|\n", r[i].rank, r[i].name, r[i].stagenum);
	}

	printf("1.메인화면으로 돌아가기\n");
	scanf("%d", &num);
	if (num == 1) {
		system("cls");
		startscreen();

	}
}
