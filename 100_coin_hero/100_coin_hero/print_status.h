#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
void print_status()
{
	//system("cls"); //화면 지우기
	int buffer[StatusSize] = { 0 };
	FILE* fp;
	fopen_s(&fp, "hero_status.txt", "r"); //용사 status 파일을 읽기

	if (fp == NULL)
	{
		printf("게임 로딩 실패\n");
		return 1;
	}

	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%d", &buffer[i]); // 배열의 크기만큼 값을 입력 받음

	}
	
	//printf("--------------------------------------------\n");
	gotoxy(2,16); 
	printf("체력: %d  ", buffer[0]);
	gotoxy(30, 16); 
	printf("공격력: %d\n", buffer[1]);
	gotoxy(2, 18); 
	printf("마나: %d  ", buffer[2]);
	gotoxy(30, 18); 
	printf("골드: %d\n", buffer[3]);

	fclose(fp);
	//printf("--------------------------------------------\n");


}
