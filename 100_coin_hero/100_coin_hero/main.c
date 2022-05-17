#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"choose_status.h"
#include"print_status.h"
#include"monster_status.h"
#include"RandomMonster.h"
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
int Stage_num = 1; //몇 스테이지인지 전역 변수로 설정

void monster_stage();

int main() 
{
	system("mode con cols=56 lines=20 | title 100-Coin-Hero");// 화면크기 설정

	choose_status();
	print_status();
	//monster_status();
	RandomMonster();
	//monster_stage();
	return 0;


}



void monster_stage()// 몬스터 스테이지 추후에 랜덤확률로 호출
{

	int monster[3] = { 0,1,1 };//1이면 몬스터 존재 0이면 몬스터 사망 추후에 랜덤으로 몬스터 수 조정 test는 일단 3마리로
	int monster_hp[3] = { 8,8,8 };
	int monster_atk = 3;
	int monster_gold = 3;


	printf("\n       -stage %d-     \n",Stage_num);



	printf("\n");
	printf("--------------------------------------------\n");

	

}
