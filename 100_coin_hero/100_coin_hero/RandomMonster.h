#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
void RandomMonster()
{
    printf("<���� ����> \n");
    srand(time(NULL));
    int  i, mon1 = 0, mon2 = 0, mon3 = 0;

    int monster_number = rand() % 3 +1;//���� �� ���� 1~3
    printf("���� �� %d \n", monster_number);
    int* monster = malloc(sizeof(int) * monster_number);


    int buffer[3] = { 0, };
    FILE* fp;

    for (int i = 0; i < monster_number; i++) {
        monster[i] = rand() %3 + 1; //1~3�� ����

        if (monster[i] == 1) {
            mon1++;
            fopen_s(&fp, "monster1_status.txt", "r");
            for (int i = 0; i < 3; i++)
            {
                fscanf(fp, "%d", &buffer[i]);
            }
            printf("-------------------monster-------------------\n");
            printf("ü��: %d  ", buffer[0]);
            printf("���ݷ�: %d\n", buffer[1]);
            printf("���: %d  \n", buffer[2]);
            printf("--------------------------------------------\n");
            fclose(fp);
        }
        else if (monster[i] == 2){
            mon2++;
            fopen_s(&fp, "monster2_status.txt", "r");
            for (int i = 0; i < 3; i++)
            {
                fscanf(fp, "%d", &buffer[i]);
            }
            printf("-------------------monster------------------\n");
            printf("ü��: %d  ", buffer[0]);
            printf("���ݷ�: %d\n", buffer[1]);
            printf("���: %d  \n", buffer[2]);
            printf("--------------------------------------------\n");
            fclose(fp);
        }
        else if (monster[i] == 3) {
            mon3++;
            fopen_s(&fp, "monster3_status.txt", "r");
            for (int i = 0; i < 3; i++)
            {
                fscanf(fp, "%d", &buffer[i]);
            }
            printf("-------------------monster------------------\n");
            printf("ü��: %d  ", buffer[0]);
            printf("���ݷ�: %d\n", buffer[1]);
            printf("���: %d  \n", buffer[2]);
            printf("--------------------------------------------\n");
            fclose(fp);
        }
    }
  
    free(monster);
}

void fight(int enemy) {
    int buffer[3] = { 0, };
    int buffer_h[StatusSize] = { 0, };
    int ch =0;

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
        
        printf("1.����\n");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("palyer-> monster ����\n");
            buffer[0] -= buffer_h[1];
            printf("monster ü�� : % d\n ", buffer[0]);
            printf("monster-> player ����\n");
            buffer_h[0] -= buffer[1];
            printf("player ü�� : %d\n ", buffer_h[0]);
            ch = 0;
        }


        if (buffer[0] <= 0)
        {
           

            return 0;
        }
        if (buffer_h[0] <= 0)
        {
            printf("���ӳ�");
            return 0;
        }

    }

    return 
    fclose(fp);
}
