

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#include<string.h>
#include"monster_list.h"
#include"RandomMonster2.h"

#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
#define monsterSize 3

void print_status();


int fight2(int *monster_number, struct monstercount a)
{


	int num = 0;
	


        int** buffer_m = (int**)malloc(sizeof(int*) * (*monster_number)); //���͵� status�� �ޱ� ���� ���߹迭
        for (int i = 0; i < *monster_number; i++) {
            buffer_m[i] = (int*)malloc(sizeof(int) * monsterSize);
        }



        int buffer_h[StatusSize] = { 0, }; //player ü�� ���ݷ� ���� ��差 �ޱ����� buffer
        FILE* fp;

        int i = 0;
        int j = 0;
        while (i < *monster_number)   //���� ����ŭ �ݺ� 
        {
            for (int j = 0; j < 10; j++) 
            {
                if (mon[j].mon > 0) //���� ���� ������  �϶�
                {
                    fopen_s(&fp, "monster_list.txt", "r");  //player status �ҷ�����

                    int lock = 1;


                    for (int i = 0; i < StatusSize; i++)
                    {
                        fscanf(fp, "%s %d %d %d %d ", &m[i].name, &m[i].hp, &m[i].atk, &m[i].gold, &m[i].lock);

                    }
                    fclose(fp);


                    fopen_s(&fp, "monster_list.txt", "w");

                    for (int i = 0; i < StatusSize; i++) {
                        if (i == j) {
                            fprintf(fp, "%s %d %d %d %d \n", m[i].name, m[i].hp, m[i].atk, m[i].gold,lock);
                        }
                        else{ fprintf(fp, "%s %d %d %d %d \n", m[i].name, m[i].hp, m[i].atk, m[i].gold, m[i].lock); }
                        

                    }
                        


                    fclose(fp);
                    
                    buffer_m[i][0] = m[j].hp;
                    buffer_m[i][1] = m[j].atk;
                    buffer_m[i][2] = m[j].gold;



                    (mon[j].mon)--;
                    i++; //���� �� 
                    fclose(fp);
                
                    
                }
            }
        
          
        };

      
           
             
      

        fopen_s(&fp, "hero_status.txt", "r");  //player status �ҷ�����
        for (int i = 0; i < StatusSize; i++)
        {
            fscanf(fp, "%d", &buffer_h[i]);
        }
        fclose(fp);



        /* for (int i = 0; i < *monster_number; i++)
         {
             for (int j = 0; j < 3; j++)
             {
                 printf("%d ", buffer_m[i][j]);
             }
             printf("\n");
         }
         ���� �迭 Ȯ��
         */
        int count = *monster_number; //�����ϱ� ���� count ����
        int ch = 0; //ch ���� ���� 
        while (1)
        {

            int mch = 0;// mch���� ����






            printf("���� ���� : ");


        back:
            for (int i = 0; i < *monster_number; i++)
            {
                if (buffer_m[i][0] <= 0)//���Ͱ� ������..
                {
                    continue;
                }
                printf("%d.���� ", i + 1);
                
            }

            


            scanf("%d", &mch);
       

            if (buffer_m[mch - 1][0] <= 0)
            {

                printf("����� ���ʹ� �����Ҽ������ϴ�!\n");
                goto back; //�ٸ����ڸ� �����ϸ�... ���ư���

            }

            printf("1.����\n2.��ų(����4�Ҹ�)\n3.������ ���\n"); //1. ���� 2.��ų 3.������ ��� ��� �߰�
            scanf("%d", &ch); // �����Է�




            if (ch == 1)
            {

                printf("palyer-> monster ����\n");
                buffer_m[mch - 1][0] -= buffer_h[1];//���� ü�¿��� �÷��̾� ���ݷ� ����
                printf("monster ü�� : % d\n ", buffer_m[mch - 1][0]);
                Sleep(1000);
                printf("monster-> player ����\n");
                buffer_h[0] -= buffer_m[mch - 1][1]; //�÷��̾� ü�¿��� ���� ���ݷ� ����
                printf("player ü�� : %d\n ", buffer_h[0]);
                Sleep(1000);
                ch = 0; //���� �ʱ�ȭ

                if (buffer_h[1] > buffer_h[7])
                {
                    buffer_h[1] = buffer_h[7]; //������ ����ȿ�� ���ֱ�
                }


                if (buffer_m[mch - 1][0] <= 0)
                {

                    buffer_h[3] += buffer_m[mch - 1][2];//���� ��� ȹ�� ��� ȹ��.

                    count--;


                }



                fopen_s(&fp, "hero_status.txt", "w");

                for (int i = 0; i < StatusSize; i++)
                    fprintf(fp, "%d\n", buffer_h[i]);


                fclose(fp);




            }

            if (ch == 2) //��ų ���
            {
                buffer_h[2] -= 4;

                if (buffer_h[2] < 0)
                {
                    printf("������ �����ϴ� �ٽü������ּ���.\n");
                    buffer_h[2] += 4;
                    ch = 0;
                    Sleep(1000);
                }
                else
                {
                    printf("palyer-> monster ���ΰ���\n");
                    for (int i = 0; i < *monster_number; i++)
                    {
                        buffer_m[i][0] -= buffer_h[1];
                        printf("monster%d ü�� : %d\n ", i, buffer_m[i][0]);
                    }
                    buffer_h[0] -= buffer_m[mch - 1][1]; //�÷��̾� ü�¿��� ���� ���ݷ� ����
                    printf("player ü�� : %d\n ", buffer_h[0]);
                    Sleep(1000);

                    if (buffer_h[1] > buffer_h[7])
                    {
                        buffer_h[1] = buffer_h[7]; //������ ����ȿ�� ���ֱ�
                    }


                    for (int i = 0; i < *monster_number; i++)
                    {
                        if (buffer_m[i][0] <= 0)
                        {
                            buffer_h[3] += buffer_m[i][2];//���� ��� ȹ�� ��� ȹ��.
                            count--;
                        }
                    }


                    fopen_s(&fp, "hero_status.txt", "w");

                    for (int i = 0; i < StatusSize; i++)
                        fprintf(fp, "%d\n", buffer_h[i]);

                    fclose(fp);


                    ch = 0;
                }

            }

            if (ch == 3) //������ ���
            {

                int pot = 0;

                printf("1. ü�� ȸ�� ���� ���\n2. ���ݷ� ��ȭ ���� ���\n3.���� ȸ�� ���� ���\n4.������");
                scanf("%d", &pot);
                if (pot == 1)
                {
                    if (buffer_h[4] > 0)
                    {
                        buffer_h[4] -= 1;
                        buffer_h[0] += 10; //ü�� 10 ����
                        printf("monster-> player ����\n");
                        buffer_h[0] -= buffer_m[mch - 1][1]; //�÷��̾� ü�¿��� ���� ���ݷ� ����
                        printf("player ü�� : %d\n ", buffer_h[0]);
                        Sleep(1000);
                    }
                    else {

                        printf("�������� �����ϴ� �ٽ� �������ּ���. \n");
                        Sleep(1000);
                        pot = 0;
                        ch = 3;

                    }

                }
                if (pot == 2)
                {
                    if (buffer_h[5] > 0)
                    {
                        buffer_h[5] -= 1;
                        buffer_h[1] += 5; //���ݷ� 5 ����
                        printf("monster-> player ����\n");
                        buffer_h[0] -= buffer_m[mch - 1][1]; //�÷��̾� ü�¿��� ���� ���ݷ� ����
                        printf("player ü�� : %d\n ", buffer_h[0]);
                        Sleep(1000);
                    }
                    else {
                        printf("�������� �����ϴ� �ٽ� �������ּ���. \n");
                        Sleep(1000);
                        pot = 0;
                        ch = 3;

                    }


                }

                if (pot == 3)
                {
                    if (buffer_h[6] > 0)
                    {
                        buffer_h[6] -= 1;
                        buffer_h[2] += 8; //���� 8 ����
                        printf("monster-> player ����\n");
                        buffer_h[0] -= buffer_m[mch - 1][1]; //�÷��̾� ü�¿��� ���� ���ݷ� ����
                        printf("player ü�� : %d\n ", buffer_h[0]);
                        Sleep(1000);
                    }
                    else {
                        printf("�������� �����ϴ� �ٽ� �������ּ���. \n");
                        Sleep(1000);
                        pot = 0;
                        ch = 3;
                    }
                }

                if (pot == 4)
                {
                    pot = 0;

                }

                fopen_s(&fp, "hero_status.txt", "w");
                for (int i = 0; i < StatusSize; i++)
                    fprintf(fp, "%d\n", buffer_h[i]);
                fclose(fp);


                ch = 0;



            }
            system("cls");
            print_status();
            printf("-------------------stage%d-------------------\n", buffer_h[9] + 1);//buffer[9]�� stage �ܰ�����
            for (int i = 0; i < *monster_number; i++)
            {
                printf("-------------------monster------------------\n");
                printf("ü��: %d  ", buffer_m[i][0]);
                printf("���ݷ�: %d\n", buffer_m[i][1]);
                printf("���: %d  \n", buffer_m[i][2]);
                printf("--------------------------------------------\n");
            }

            if (count <= 0)
            {
                printf("------------------stage����------------------\n"); //���� ����
                break;
            }



            if (buffer_h[0] <= 0) //�÷��̾� ü���� 0���� �̸� ����
            {
                printf("GAME OVER\n");
                return 0;
            }

        }


        buffer_h[9] += 1; //stage num ����.


        fopen_s(&fp, "hero_status.txt", "w");

        for (int i = 0; i < StatusSize; i++)
            fprintf(fp, "%d\n", buffer_h[i]);


        fclose(fp);






        for (int i = 0; i < *monster_number; i++)  //�����޸� ����
        {
            free(buffer_m[i]);
        }
        free(buffer_m);



    }


