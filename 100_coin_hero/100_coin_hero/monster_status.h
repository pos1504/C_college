#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void monster_status()
{
    int num;
    printf("<monster의 status> \n\n");
    int buffer[3] = { 0, };
    FILE* fp;


    fopen_s(&fp, "monster1_status.txt", "r"); // 몬스터1 status 파일 읽기
    if (fp == NULL)
    {
        printf("게임 로딩 실패\n");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &buffer[i]);
    }
    printf("몬스터1 hp: %d \n", buffer[0]);
    printf("몬스터1 공격력: %d\n", buffer[1]);
    printf("몬스터1 처리 시 얻을 수 있는 골드: %d\n", buffer[2]);

    fclose(fp);
    printf("--------------------------------------------\n");

    fopen_s(&fp, "monster2_status.txt", "r"); // 몬스터2 status 파일 읽기
    if (fp == NULL)
    {
        printf("게임 로딩 실패\n");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &buffer[i]);
    }
    printf("몬스터2 hp: %d\n", buffer[0]);
    printf("몬스터2 공격력: %d\n", buffer[1]);
    printf("몬스터2 처리 시 얻을 수 있는 골드: %d\n", buffer[2]);

    fclose(fp);
    printf("--------------------------------------------\n");

    fopen_s(&fp, "monster3_status.txt", "r"); // 몬스터3 status 파일 읽기
    if (fp == NULL)
    {
        printf("게임 로딩 실패\n");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &buffer[i]);
    }
    printf("몬스터3 hp: %d\n", buffer[0]);
    printf("몬스터3 공격력: %d\n", buffer[1]);
    printf("몬스터3 처리 시 얻을 수 있는 골드: %d\n", buffer[2]);

    fclose(fp);
    printf("--------------------------------------------\n");
}

