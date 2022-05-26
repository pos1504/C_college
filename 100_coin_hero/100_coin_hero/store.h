#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
void print_status();
void fight();

void store()
{
	system("cls");

	int buffer[StatusSize] = { 0 };
	FILE* fp;
	fopen_s(&fp, "hero_status.txt", "r"); //용사 status 파일 읽기

	if (fp == NULL)
	{
		printf("게임 로딩 실패\n");
		return 1;
	}
	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%d", &buffer[i]);

	}
	fclose(fp);
	printf("-------------------player-------------------\n");
	printf("체력: %d  ", buffer[0]);
	printf("공격력: %d\n", buffer[1]);
	printf("마나: %d  ", buffer[2]);
	printf("골드: %d\n", buffer[3]);
	printf("체력 회복 포션: %d\n", buffer[4]);
	printf("공격력 강화 포션: %d\n", buffer[5]);
	printf("--------------------------------------------\n");

	printf("-------------------stage%d-------------------\n", buffer[9] + 1);//buffer[9]에 stage 단계저장
	printf("===============상점===============\n"); // 상점
	printf("(1) 체력 회복 포션 - 2골드\n");
	printf("(2) 공격력 강화 포션 - 4골드\n");
	printf("==================================\n");

	int count1 = 0; int count2 = 0; // count1: 체력 회복 포션 수, count2: 공격력 강화 포션 수
	int gold = buffer[3]; // buffer[3]에 있는 골드값 받아옴

	printf("체력 회복 포션을 몇 개 구매하시겠습니까?\n");
	scanf("%d", &count1);
		if (gold-2*count1 >= 0) {
			printf("체력 회복 포션: %d개\n", count1);
			gold -= 2 * count1;
			printf("남은 골드: %d \n", gold);
		}
		else {
			printf("골드가 부족합니다.\n");
			count1 = 0; // 골드 부족-> 입력받은 count값 0으로 출력
			
		}
	
	printf("공격력 강화 포션을 몇 개 구매하시겠습니까?\n");
	scanf("%d", &count2);
		if (gold-4*count2 >= 0) {
			printf("공격력 회복 포션: %d개 \n", count2);
			gold -= 4 * count2;
			printf("남은 골드: %d\n", gold);
		}
		else {
			printf("골드가 부족합니다.\n"); // 골드 부족-> 입력받은 count값 0으로 출력
			count2 = 0;
			
		}
		

	buffer[3] = gold;
	buffer[4] += count1;
	buffer[5] += count2;
	buffer[9] += 1; //stage num 증가.
	
	printf("-------------------player-------------------\n");
	printf("체력: %d  ", buffer[0]);
	printf("공격력: %d\n", buffer[1]);
	printf("마나: %d  ", buffer[2]);
	printf("골드: %d\n", buffer[3]);
	printf("체력 회복 포션: %d\n", buffer[4]);
	printf("공격력 강화 포션: %d\n", buffer[5]);
	printf("--------------------------------------------\n");
	

	fopen_s(&fp, "hero_status.txt", "w");

	for (int i = 0; i < StatusSize; i++)
		fprintf(fp, "%d\n", buffer[i]);


	fclose(fp);
}