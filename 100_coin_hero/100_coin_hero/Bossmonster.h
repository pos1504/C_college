#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
#include"monster_list.h"
void print_status();
#include"RandomMonster2.h"


void BossMonster(int* monster_number, struct monstercount a)
{
    print_status();

    printf("<���� ����> \n");
    srand(time(NULL));
    int  i = 0;
    FILE* fp;
    *monster_number = rand() % 3 + 1;//���� �� ���� 1~3
    printf("���� �� %d \n", *monster_number);
    int* monster = (int*)malloc(sizeof(int) * (*monster_number));


    //&m[i].name, &m[i].hp, &m[i].atk, &m[i].gold, &m[i].lock
    for (int i = 0; i < *monster_number; i++) {
        monster[i] = 9; //1~8�� ���� ���� ����
        for (int j = 1; j < 11; j++)
        {
            if (monster[i] == j) {
                (mon[j].mon)++;
                fopen_s(&fp, "monster_list.txt", "r");  //

                for (int i = 0; i < StatusSize; i++)
                {
                    fscanf(fp, "%s %d %d %d %d", &m[i].name, &m[i].hp, &m[i].atk, &m[i].gold, &m[i].lock);

                }
                printf("--------------------%s-------------------\n", m[j].name);
                printf("ü��: %d  ", m[j].hp);
                printf("���ݷ�: %d\n", m[j].atk);
                printf("���: %d  \n", m[j].gold);
                printf("--------------------------------------------\n");
                fclose(fp);

            }



        }




    }

    /*for (int i = 0; i < 10; i++) {
        printf("%d : %d \n", i, mon[i].mon);

    }*/


    free(monster);
}


