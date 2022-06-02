#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
#define MAX 5

// 100골드를 모으기까지 stage의 수가 적을수록 순위가 높음

int ranking(void) 
{	
	system("cls");
	char name[10];
	int stagenum[20];

	FILE* stream;
	stream = fopen("name.txt", "r");
	printf("player 이름: %s\n", name);
	

	int buffer[StatusSize] = { 0 };
	FILE* fp = fopen("hero_status.txt", "r");
	buffer[9] = stagenum;
	printf("stage 수: %d\n", stagenum);
	
	
	int i; int j; int rank[MAX];

	for (i = 0; i < MAX; i++)
	{
		printf("player 정보\n");
		printf("->player 이름: %s\n", name); 
		printf("->stage 수: %d\n", stagenum);  
	}
	
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (stagenum[i] > stagenum[j])
			{
				rank[i] += 1;
			}
		}
	}

	printf("%4s| %4s| %8s| \n","순위" "player 이름", "stage 수");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d| %8s| %4d|\n",
			rank, name, stagenum);
	}
	fclose(stream);
	fclose(fp);
}
