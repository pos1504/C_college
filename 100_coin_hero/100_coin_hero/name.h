#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10


void name(void)
{
	system("cls");//ȭ�������
	
	FILE* stream;
	char name[10];

	stream= fopen("name.txt", "w");
	printf("�̸��� �Է��ϼ���.\n");
	
	scanf("%s", &name); 
	fputs(name, stream);

	fclose(stream);
}