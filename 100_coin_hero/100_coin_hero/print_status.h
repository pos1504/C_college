#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
void print_status()
{
	//system("cls"); //ȭ�� �����
	int buffer[StatusSize] = { 0 };
	FILE* fp;
	fopen_s(&fp, "hero_status.txt", "r"); //��� status ������ �б�

	if (fp == NULL)
	{
		printf("���� �ε� ����\n");
		return 1;
	}

	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%d", &buffer[i]); // �迭�� ũ�⸸ŭ ���� �Է� ����

	}
	
	//printf("--------------------------------------------\n");
	gotoxy(2,16); 
	printf("ü��: %d  ", buffer[0]);
	gotoxy(30, 16); 
	printf("���ݷ�: %d\n", buffer[1]);
	gotoxy(2, 18); 
	printf("����: %d  ", buffer[2]);
	gotoxy(30, 18); 
	printf("���: %d\n", buffer[3]);

	fclose(fp);
	//printf("--------------------------------------------\n");


}
