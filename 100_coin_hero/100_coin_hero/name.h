#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10


void name(void)
{
	system("cls");//화면지우기
	
	FILE* stream;
	char name[10];

	stream= fopen("name.txt", "w");
	printf("이름을 입력하세요.\n");
	
	scanf("%s", &name); 
	fputs(name, stream);

	fclose(stream);
}