
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10






void fight(int enemy)  // fight함수를 구현을 위해 RandomMonster에서 값을 받아와야 되는데 추후 추가예정
{
    int buffer[3] = { 0, }; //몬스터 체력 공격력 골드량 받기위한 buffer
    int buffer_h[StatusSize] = { 0, }; //player 체력 공격력 마나 골드량 받기위한 buffer
    

    FILE* fp;



    if (enemy == 1) //몬스터 종류 1일때
    {
        fopen_s(&fp, "monster1_status.txt", "r"); //monster 1 txt 열기 
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]); //체력 공격력 골드량 불러오기
        }
    }
    else if (enemy == 2) //몬스터 종류 2일때
    {
        fopen_s(&fp, "monster2_status.txt", "r");
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]); //체력 공격력 골드량 불러오기
        }
    }
    else //몬스터 종류 3일때 else 처리 
    {
        fopen_s(&fp, "monster3_status.txt", "r");
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]); //체력 공격력 골드량 불러오기
        }
    }

     
    fopen_s(&fp, "hero_status.txt", "r+");  //player status 불러오기
    for (int i = 0; i < StatusSize; i++)
    {
        fscanf(fp, "%d", &buffer_h[i]);
    }

    while (1) 
    {
        int ch = 0;
        printf("1.공격\n");// 1. 공격 2.스킬 3.아이템 사용 등등 추가 할 예정...
        scanf("%d", &ch); // 숫자입력

        if (ch == 1)
        {
            printf("palyer-> monster 공격\n");
            buffer[0] -= buffer_h[1];//몬스터 체력에서 플레이어 공격력 빼기 
            printf("monster 체력 : % d\n ", buffer[0]);
            printf("monster-> player 공격\n");
            buffer_h[0] -= buffer[1]; //플레이어 체력에서 몬스터 공격력 빼기 
            printf("player 체력 : %d\n ", buffer_h[0]);
            ch = 0; //숫자 초기화 
        }


        if (buffer[0] <= 0) //몬스터 체력이 0이하 이면 종료
        {


            return 0;
        }
        if (buffer_h[0] <= 0) //플레이어 체력이 0이하 이면 종료
        {
            printf("게임끝");
            return 0;
        }

    }


    fclose(fp);
}