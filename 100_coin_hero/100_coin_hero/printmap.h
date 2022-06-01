#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10



struct map
{
	int stagetype[2];
	int size;

};



void printmap() {
	struct map map[5]; //map길이 5



	srand(time(NULL));
	
	int random_tree = 0; // 갈림길 구현..

	for (int i = 0; i < 5; i++)
	{
		random_tree = rand() % 2+1;
		for (int j = 0; i < 2; j++)
		{
			map[i].size = random_tree;
		}

	}


	for (int i = 0; i < 5; i++)
	{
		random_tree = rand() % 2 +1;
		for (int j = 0; i < 2; j++)
		{
			if (map[i].size > j)
			{
				map[i].stagetype[j] = random_tree;
			}
			else
			{
				map[i].stagetype[j] = 0;
			}
		}
		
	}
	map[4].stagetype[0] = 3; // 마지막 map은 보스스테이지
	map[4].stagetype[1] = 0; // 
	map[4].size = 1; // size 는 1로 제한 

	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; i < 2; j++)
		{
			printf("map[%d].size = %d ",i, map[i].size);
			printf("map[%d].stagetyep[%d] = %d \n", i,j, map[i].stagetype[j]);
		}

	}

}

