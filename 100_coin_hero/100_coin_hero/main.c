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
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10

int main() 
{	
	int monster_number=0   , mon1=0 , mon2=0 , mon3=0 ;

	

	//choose_status();
	
	
	print_status();

	RandomMonster(&monster_number, &mon1, &mon2, &mon3);
	//monster_status();
	printf("monster_number : %d mon1 : %d mon2 : %d mon3 :  %d\n",monster_number,mon1,mon2,mon3);
	fight(&monster_number,&mon1,&mon2,&mon3);
	



	
	
	return 0;


}
