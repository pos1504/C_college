
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10






void fight(int enemy)  // fight�Լ��� ������ ���� RandomMonster���� ���� �޾ƿ;� �Ǵµ� ���� �߰�����
{
    int buffer[3] = { 0, }; //���� ü�� ���ݷ� ��差 �ޱ����� buffer
    int buffer_h[StatusSize] = { 0, }; //player ü�� ���ݷ� ���� ��差 �ޱ����� buffer
    

    FILE* fp;



    if (enemy == 1) //���� ���� 1�϶�
    {
        fopen_s(&fp, "monster1_status.txt", "r"); //monster 1 txt ���� 
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]); //ü�� ���ݷ� ��差 �ҷ�����
        }
    }
    else if (enemy == 2) //���� ���� 2�϶�
    {
        fopen_s(&fp, "monster2_status.txt", "r");
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]); //ü�� ���ݷ� ��差 �ҷ�����
        }
    }
    else //���� ���� 3�϶� else ó�� 
    {
        fopen_s(&fp, "monster3_status.txt", "r");
        for (int i = 0; i < 3; i++)
        {
            fscanf(fp, "%d", &buffer[i]); //ü�� ���ݷ� ��差 �ҷ�����
        }
    }

     
    fopen_s(&fp, "hero_status.txt", "r+");  //player status �ҷ�����
    for (int i = 0; i < StatusSize; i++)
    {
        fscanf(fp, "%d", &buffer_h[i]);
    }

    while (1) 
    {
        int ch = 0;
        printf("1.����\n");// 1. ���� 2.��ų 3.������ ��� ��� �߰� �� ����...
        scanf("%d", &ch); // �����Է�

        if (ch == 1)
        {
            printf("palyer-> monster ����\n");
            buffer[0] -= buffer_h[1];//���� ü�¿��� �÷��̾� ���ݷ� ���� 
            printf("monster ü�� : % d\n ", buffer[0]);
            printf("monster-> player ����\n");
            buffer_h[0] -= buffer[1]; //�÷��̾� ü�¿��� ���� ���ݷ� ���� 
            printf("player ü�� : %d\n ", buffer_h[0]);
            ch = 0; //���� �ʱ�ȭ 
        }


        if (buffer[0] <= 0) //���� ü���� 0���� �̸� ����
        {


            return 0;
        }
        if (buffer_h[0] <= 0) //�÷��̾� ü���� 0���� �̸� ����
        {
            printf("���ӳ�");
            return 0;
        }

    }


    fclose(fp);
}