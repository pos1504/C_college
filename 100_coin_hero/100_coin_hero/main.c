#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"choose_status.h"
#include"print_status.h"
#include"monster_status.h"
#include"RandomMonster.h"
#include"gotoxy.h"
#include"fight.h"
#include"store.h"
#include"ranking.h"
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10

void startscreen() {

	int n;
	printf("1. 처음 시작 \n2. 이어 하기\n3. 플레이어 순위\n"); 
	scanf("%d",&n );

	if (n == 1) {
		choose_status();
		
	}
	/*if (n == 2)
	{

	}*/
	if (n == 3)
	{
		ranking();
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
	
	int buffer_h[StatusSize] = { 0, }; //player 체력 공격력 마나 골드량 받기위한 buffer
	FILE* fp;
	srand(time(NULL));

	fopen_s(&fp, "hero_status.txt", "r");  //player status 불러오기

	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%d", &buffer_h[i]);
	}
	fclose(fp);


	while (buffer_h[3] < 100)// 골드량이 100크면 종료
	{
		
		random_stage = rand() % 3;

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

	startscreen();

	//choose_status();
	
	
	
	roop();
	/*print_status();

	RandomMonster(&monster_number, &mon1, &mon2, &mon3);
	
	printf("monster_number : %d mon1 : %d mon2 : %d mon3 :  %d\n",monster_number,mon1,mon2,mon3);
	fight(&monster_number,&mon1,&mon2,&mon3);
	store();
	*/
	ranking();


	
	
	return 0;


}


