﻿
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
void choose_status()
{
	system("cls");//화면지우기
	
	char name[10]; //이름 입력
	printf("이름 입력: ");
	scanf("%s", &name);
	printf("player 이름: %s\n", name);

	int num;
	printf("캐릭터를 선택하세요.\n");
	printf("1. 검사   2.법사   3.도적 \n");
	scanf("%d", &num);
	if (num == 1)
	{
		FILE* fp = fopen("hero_status.txt", "w"); //용사 status 파일을 쓰기

		int hero_status[StatusSize] = { 30,4,10,5 }; //검사 status 
		for (int i = 0; i < StatusSize; i++)
			fprintf(fp, "%d\n", hero_status[i]); //0.체력 1.공격력 2.마나 3.골드량 4.... 9.stage number



		fclose(fp);
	}

	if (num == 2)
	{
		FILE* fp = fopen("hero_status.txt", "w"); 

		int hero_status[StatusSize] = { 100,20,20,10 };  
		for (int i = 0; i < StatusSize; i++)
			fprintf(fp, "%d\n", hero_status[i]); 



		fclose(fp);
	}

	if (num == 3)
	{
		FILE* fp = fopen("hero_status.txt", "w"); 

		int hero_status[StatusSize] = { 18,3,12,5 }; //도적 status 
		for (int i = 0; i < StatusSize; i++)
			fprintf(fp, "%d\n", hero_status[i]); 



		fclose(fp);
	}
	system("cls");//화면지우기




}
