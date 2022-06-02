#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"name.h"
#include"choose_status.h"
#include"print_status.h"
#include"monster_status.h"
#include"RandomMonster.h"
#include"gotoxy.h"
#include"fight.h"
#include"store.h"
#include"monster_list.h"
#include"ranking.h"

#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10



struct map
{
	int stagetype[2];
	int size;

}map1[5];

void createmap() {

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


}



void printmap() {
	system("cls");
	print_status();
	
	int buffer_h[StatusSize] = { 0, }; //player 체력 공격력 마나 골드량 받기위한 buffer
	FILE* fp;
	
	fopen_s(&fp, "hero_status.txt", "r");  //player status 불러오기

	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%d", &buffer_h[i]);
	}
	fclose(fp);


	int stagenum = buffer_h[9] % 5;
	

	

	if (stagenum == 0) {
		printf("    ▣\n");
	}

	if (map1[0].size == 1)
	{

		
		printf("    ↓ \n");

	}


	if (map1[0].size == 2)
	{
		printf("  ↙  ↘ \n");
	}

	for (int i = 0; i < 5; i++)
	{



		if (i > 0)
		{
			if (map1[i].size == 2 && map1[i - 1].size == 1)
			{
				printf("  ↙  ↘ \n");
			}

		}


		for (int j = 0; j < 2; j++)
		{
			if (map1[i].stagetype[j] == 1)
			{
				if (map1[i].stagetype[1] == 0)
				{
					if (stagenum == i)
					{
						printf(">");
					}
					else {
						printf(" ");
					}
					printf("   ●  ");
				}
				else
				{
					if (stagenum == i)
					{
						printf(">");
					}
					else {
						printf(" ");
					}
					printf(" ● ");
				}


			}
			if (map1[i].stagetype[j] == 2)
			{
				if (map1[i].stagetype[1] == 0)
				{
					if (stagenum == i)
					{
						printf(">");
					}
					else {
						printf(" ");
					}
					printf("   ♨  ");
				}
				else
				{
					if (stagenum == i)
					{
						printf(">");
					}
					else {
						printf(" ");
					}
					printf(" ♨ ");
				}

			}
			if (map1[i].stagetype[j] == 3)
			{
				if (map1[i].stagetype[1] == 0)
				{
					if (stagenum == i)
					{
						printf(">");
					}
					else {
						printf(" ");
					}
					printf("   ★  ");
				}
				else
				{
					if (stagenum == i)
					{
						printf(">");
					}
					else {
						printf(" ");
					}
					printf(" ★ ");
				}

			}
			//printf("map1[%d].size = %d ", i, map1[i].size);
			//printf("map1[%d].stagetyep[%d] = %d \n", i, j, map1[i].stagetype[j]);
		}
		printf("\n");

		if (map1[i].size == 1 && map1[i + 1].size == 1)
		{
			printf("    ↓ \n");

		}

		if (map1[i].size == 2 && map1[i + 1].size == 2)
		{
			printf("  ↓   ↓ \n");

		}
		if (map1[i].size == 2 && map1[i + 1].size == 1)
		{
			printf("  ↘  ↙ \n");
		}

	}
	printf("●몬스터 ♨상점 ★보스 \n");

}












void startscreen() {

	int n;
	printf("1. 처음 시작 \n2. 이어 하기\n3. 플레이어 순위\n4. 몬스터 도감\n"); 
	scanf("%d",&n );

	if (n == 1) {
		name();
		choose_status();
		
	}
	if (n == 2)
	{
		
	}
	if (n == 3)
	{
		ranking();
	}
	if(n==4)
	{
		monster_list();
	}
	else 
	{
		return 0;
	}
}
void roop() {
	int monster_number = 0, mon1 = 0, mon2 = 0, mon3 = 0;
	int random_stage = 0;
	int no_twice = 2;
	int num = 0;
	int temp = 0;
	int whatever = 0;
	
	int buffer_h[StatusSize] = { 0, }; //player 체력 공격력 마나 골드량 받기위한 buffer
	FILE* fp;
	srand(time(NULL));

	fopen_s(&fp, "hero_status.txt", "r");  //player status 불러오기

	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%d", &buffer_h[i]);
	}
	fclose(fp);

	
	createmap();


	while (buffer_h[3] < 100)// 골드량이 100크면 종료
	{
		int stagenum = buffer_h[9] % 5;
		
		
		
		if (stagenum > 4)
		{
			createmap();
			
		}

		printmap();
		printf("-------------------stage%d-------------------\n", buffer_h[9] + 1);//buffer[9]에 stage 단계저장
		/*random_stage = rand() % 3;

		print_status();

		printf("-------------------stage%d-------------------\n", buffer_h[9]+1);//buffer[9]에 stage 단계저장
		
		if (random_stage < 2)
		{
			RandomMonster(&monster_number, &mon1, &mon2, &mon3);
			fight(&monster_number, &mon1, &mon2, &mon3);
		}

		else 
		{
			if(no_twice == random_stage)//첫번째 스테이지 그리고  상점 연속으로 두번이상 못들어가게 지정
			{
				continue;
			}
			store();
		}

		no_twice = random_stage;
		*/

		
		if (stagenum == 0) {
			if (map1[0].size == 1)
			{
				printf("1.go ↓\n ");
				scanf("%d", &num);
			}

			if (map1[0].size == 2)
			{
				printf("1.go ↙ 2.go↘\n ");
				scanf("%d", &num);
			}
		}
		
	
		else if (stagenum > 0) {
			
			if (map1[stagenum].size == 1 && map1[stagenum - 1].size == 1)
			{
				
				printf("1.go ↓\n ");
				scanf("%d", &num);
				

			}

			else if (map1[stagenum].size == 1 && map1[stagenum - 1].size == 2)
			{

				printf("1.go ↓\n ");
				scanf("%d", &num);

			}
			
			else if (map1[stagenum].size == 2 && map1[stagenum - 1].size == 1)
			{

				printf("1.go ↙ 2.go↘\n ");
				scanf("%d", &num);

			}

			else if (map1[stagenum].size == 2 && map1[stagenum - 1].size == 2)
			{
				 
				printf("1.go ↓\n ");
				scanf("%d", &num);
				num = temp;
			}
		}
		if (map1[stagenum].stagetype[(num-1)] == 1)
		{
			RandomMonster(&monster_number, &mon1, &mon2, &mon3);
			fight(&monster_number, &mon1, &mon2, &mon3);
			
			stagenum++;
			temp = num;
			num = 0;
			
		}
		else if (map1[stagenum].stagetype[(num - 1)] == 2)
		{
			store();

			stagenum++;
			temp = num;
			num = 0;
			
		}
		else if (map1[stagenum].stagetype[(num - 1)] == 3)
		{
			RandomMonster(&monster_number, &mon1, &mon2, &mon3);
			fight(&monster_number, &mon1, &mon2, &mon3); // 보스로 변경 시키기

			stagenum++;
			temp = num;
			num = 0;
		}
		
		fopen_s(&fp, "hero_status.txt", "r");  //player status 불러오기
		for (int i = 0; i < StatusSize; i++)
		{
			fscanf(fp, "%d", &buffer_h[i]);
		}
		fclose(fp);


		

		
			
		
	}

	printf("게임종료!\n");


}








int main() 
{	
	int monster_number=0   , mon1=0 , mon2=0 , mon3=0 ;
	//createmap();
	//printmap();
	//printmap();

	/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			printf("map1[%d].size = %d ", i, map1[i].size);
			printf("map1[%d].stagetyep[%d] = %d \n", i, j, map1[i].stagetype[j]);
		}
	}
	
		*/	
	startscreen();

	//choose_status();
	//store();
	
	
	roop();
	/*print_status();

	RandomMonster(&monster_number, &mon1, &mon2, &mon3);
	
	printf("monster_number : %d mon1 : %d mon2 : %d mon3 :  %d\n",monster_number,mon1,mon2,mon3);
	fight(&monster_number,&mon1,&mon2,&mon3);
	store();
	*/
	//ranking();


	
	
	return 0;


}


