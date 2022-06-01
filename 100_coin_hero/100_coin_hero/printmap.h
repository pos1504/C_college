#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
void print_status();

struct map
{
	int stagetype[2];
	int size;

};



void printmap() {
	system("cls");
	print_status();
	struct map map1[5]; //map길이 5



	srand(time(NULL));

	int random_tree; // 갈림길 구현..

	for (int i = 0; i < 5; i++)
	{
		random_tree = rand() % 2 + 1;

		map1[i].size = random_tree;


	}


	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 2; j++)
		{

			if (map1[i].size > j)
			{
				random_tree = rand() % 2 + 1;
				map1[i].stagetype[j] = random_tree;
			}
			else
			{
				map1[i].stagetype[j] = 0;
			}
		}

	}
	map1[4].stagetype[0] = 3; // 마지막 map은 보스스테이지
	map1[4].stagetype[1] = 0; // 
	map1[4].size = 1; // size 는 1로 제한 



	printf("  YOU \n");

	if (map1[0].size == 1 )
	{
		printf("  ↓ \n");

	}


	if (map1[0].size == 2 )
	{
		printf(" ↙ ↘ \n");
	}

	for (int i = 0; i < 5; i++)
	{
		


		if (i > 0)
		{
			if (map1[i].size == 2 && map1[i - 1].size == 1)
			{
				printf(" ↙ ↘ \n");
			}

		}


		for (int j = 0; j < 2; j++)
		{
			if (map1[i].stagetype[j] == 1)
			{
				if (map1[i].stagetype[1] == 0)
				{
					printf("  ●  ");
				}
				else
				{
					printf(" ● ");
				}


			}
			if (map1[i].stagetype[j] == 2)
			{
				if (map1[i].stagetype[1] == 0)
				{
					printf("  ♨  ");
				}
				else
				{
					printf(" ♨ ");
				}

			}
			if (map1[i].stagetype[j] == 3)
			{
				if (map1[i].stagetype[1] == 0)
				{
					printf("  ★  ");
				}
				else
				{
					printf(" ★ ");
				}

			}
			//printf("map1[%d].size = %d ", i, map1[i].size);
			//printf("map1[%d].stagetyep[%d] = %d \n", i, j, map1[i].stagetype[j]);
		}
		printf("\n");

		if (map1[i].size == 1 && map1[i + 1].size == 1)
		{
			printf("  ↓ \n");

		}

		if (map1[i].size == 2 && map1[i + 1].size == 2)
		{
			printf(" ↓  ↓ \n");

		}
		if (map1[i].size == 2 && map1[i + 1].size == 1)
		{
			printf(" ↘ ↙ \n");
		}

	}
	printf("●몬스터 ♨상점 ★보스 \n");
}