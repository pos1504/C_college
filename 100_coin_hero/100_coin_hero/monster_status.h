#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void monster_status()
{
    int num;
    printf("<monster�� status> \n\n");
    int buffer[3] = { 0, };
    FILE* fp;


    fopen_s(&fp, "monster1_status.txt", "r"); // ����1 status ���� �б�
    if (fp == NULL)
    {
        printf("���� �ε� ����\n");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &buffer[i]);
    }
    printf("����1 hp: %d \n", buffer[0]);
    printf("����1 ���ݷ�: %d\n", buffer[1]);
    printf("����1 ó�� �� ���� �� �ִ� ���: %d\n", buffer[2]);

    fclose(fp);
    printf("--------------------------------------------\n");

    fopen_s(&fp, "monster2_status.txt", "r"); // ����2 status ���� �б�
    if (fp == NULL)
    {
        printf("���� �ε� ����\n");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &buffer[i]);
    }
    printf("����2 hp: %d\n", buffer[0]);
    printf("����2 ���ݷ�: %d\n", buffer[1]);
    printf("����2 ó�� �� ���� �� �ִ� ���: %d\n", buffer[2]);

    fclose(fp);
    printf("--------------------------------------------\n");

    fopen_s(&fp, "monster3_status.txt", "r"); // ����3 status ���� �б�
    if (fp == NULL)
    {
        printf("���� �ε� ����\n");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &buffer[i]);
    }
    printf("����3 hp: %d\n", buffer[0]);
    printf("����3 ���ݷ�: %d\n", buffer[1]);
    printf("����3 ó�� �� ���� �� �ִ� ���: %d\n", buffer[2]);

    fclose(fp);
    printf("--------------------------------------------\n");
}

