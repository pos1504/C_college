#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include"choose_status.h"
#include"print_status.h"
#include"monster_status.h"
#include"RandomMonster.h"
#include"gotoxy.h"
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
int Stage_num = 1; //몇 스테이지인지 전역 변수로 설정

void monster_stage();

int main() 
{
	

	choose_status();
	
	
	print_status();

	RandomMonster();
	//monster_status();
	fight(1);



	
	
	return 0;


}
