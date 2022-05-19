
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10






void fight(int enemy) {
    int buffer[3] = { 0, };
    int buffer_h[StatusSize] = { 0, };
    int ch = 0;

    FILE* fp;



    if (enemy == 1)
    {
        fopen_s(&fp, "monster1_status.txt", "r");
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]);
        }
    }
    else if (enemy == 2)
    {
        fopen_s(&fp, "monster2_status.txt", "r");
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]);
        }
    }
    else
    {
        fopen_s(&fp, "monster3_status.txt", "r");
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]);
        }
    }


    fopen_s(&fp, "hero_status.txt", "r+");
    for (int i = 0; i < StatusSize; i++)
    {
        fscanf(fp, "%d", &buffer_h[i]);
    }

    while (1)
    {

        printf("1.공격\n");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("palyer-> monster 공격\n");
            buffer[0] -= buffer_h[1];
            printf("monster 체력 : % d\n ", buffer[0]);
            printf("monster-> player 공격\n");
            buffer_h[0] -= buffer[1];
            printf("player 체력 : %d\n ", buffer_h[0]);
            ch = 0;
        }


        if (buffer[0] <= 0)
        {


            return 0;
        }
        if (buffer_h[0] <= 0)
        {
            printf("게임끝");
            return 0;
        }

    }


    fclose(fp);
}