#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
#define MAX 5

// 100��带 ��������� stage�� ���� �������� ������ ����

int ranking(void) 
{	
	system("cls");
	char name[20] = { 0, };
	int stagenum;

	FILE* fp;
	fp = fopen("name.txt", "r");
	
	fgets(name, sizeof(name), fp);
	printf("player �̸�: %s\n", name);

	fclose(fp);

	int buffer[StatusSize] = { 0 };
	FILE* f = fopen("hero_status.txt", "r");
	fscanf(f, "%d",buffer[9]);
	stagenum = buffer[9];
	printf("stage ��: %d\n", stagenum);
	fclose(f);
	
	int i; int j; int rank[MAX];

	for (i = 0; i < MAX; i++)
	{
		printf("player ����\n");
		printf("->player �̸�: %s\n", name); 
		printf("->stage ��: %d\n", stagenum);  
	}
	
	/*for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (stagenum[i] > stagenum[j])
			{
				rank[i] += 1;
			}
		}
	}

	//printf("%4s| %4s| %8s| \n","����" "player �̸�", "stage ��");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d| %8s| %4d|\n",
			rank, name, stagenum);
	}
	*/
	
}
