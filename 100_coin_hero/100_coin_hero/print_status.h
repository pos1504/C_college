#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 10

void print_status()
{

	int i;
	int buffer[MAX] = { 0 };
	FILE* fp;
	fopen_s(&fp, "hero_status.txt", "r");

	if (fp == NULL)
	{
		printf("게임 로딩 실패\n");
		return 1;
	}

	for (int i = 0; i < MAX; i++)
	{
		fscanf(fp, "%d", &buffer[i]);

	}
	printf("체력: %d\n", buffer[0]);
	printf("공격력: %d\n", buffer[1]);
	printf("마나: %d\n", buffer[2]);
	printf("골드: %d\n", buffer[3]);

	fclose(fp);
	printf("--------------------------------------------");

}
