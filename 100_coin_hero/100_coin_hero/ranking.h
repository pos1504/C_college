#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
#define MAX 5

// 100��带 ��������� stage�� ���� �������� ������ ����

struct Player
{
	char name[20];
	int stagenum;
	int rank;
};

int ranking(void) 
{	
	system("cls");
	
	int i; int j;
	
	struct Player player_list[MAX];

	for (i = 0; i < MAX; i++) {
		player_list[i].rank = 0;
	}
	
	
	for (i = 0; i < MAX; i++)
	{
		printf("player %d ���� �Է� \n", i + 1);
		printf("->player �̸�: "); scanf("%s", player_list[i].name); //�̸� �Է�
		printf("->stage ��: "); scanf("%d", &player_list[i].stagenum); //stage �� �Է�
	}
	
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (player_list[i].stagenum > player_list[j].stagenum) 
			{
				player_list[i].rank=player_list[i].rank+1;
			}
		}
	}

	printf("%4s| %4s| %8s| \n","����" "player �̸�", "stage ��");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d| %4s| %8d|\n",player_list[i].rank, player_list[i].name, player_list[i].stagenum);
	}
}