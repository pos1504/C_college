
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
#define monsterSize 3
void print_status();




void fight(int *monster_number, int* mon1, int* mon2, int* mon3)  // fight�Լ��� ������ ���� RandomMonster���� ���� �޾ƿ;� �Ǵµ� ���� �߰�����
{




    int** buffer_m = (int**)malloc(sizeof(int*) * (*monster_number)); //���͵� status�� �ޱ� ���� ���߹迭
    for (int i = 0; i < *monster_number; i++) {
        buffer_m[i] = (int*)malloc(sizeof(int) * monsterSize); 
    }



    int buffer_h[StatusSize] = { 0, }; //player ü�� ���ݷ� ���� ��差 �ޱ����� buffer


    FILE* fp;
    int i = 0;
    while (i < *monster_number)   //���� ����ŭ �ݺ� 
    {
        
        
        if (*mon1 > 0) //���� ����1 �϶�
        {

            fopen_s(&fp, "monster1_status.txt", "r"); //monster 1 txt ���� 

            if (fp == NULL)
            {
                printf("���� �ε� ����\n");
                return 1;
            }
            
                for (int j = 0; j < 3; j++)
                {
                    fscanf(fp, "%d", &buffer_m[i][j]); //ü�� ���ݷ� ��差 �ҷ�����
                }

            
            (*mon1)--;
            i++;
            fclose(fp);
        }

        else if (*mon2 > 0) //���� ���� 1�϶�
        {
            fopen_s(&fp, "monster2_status.txt", "r"); //monster 1 txt ���� 
            if (fp == NULL)
            {
                printf("���� �ε� ����\n");
                return 1;
            }


                for (int j = 0; j < 3; j++)
                {
                    fscanf(fp, "%d", &buffer_m[i][j]); //ü�� ���ݷ� ��差 �ҷ�����
                }

             i++;
            (*mon2)--;
            fclose(fp);
        }

        else
        {
            fopen_s(&fp, "monster3_status.txt", "r"); //monster 2 txt ���� 

            if (fp == NULL)
            {
                printf("���� �ε� ����\n");
                return 1;
            }

            
                for (int j = 0; j < 3; j++)
                {
                    fscanf(fp, "%d", &buffer_m[i][j]); //ü�� ���ݷ� ��差 �ҷ�����
                }

            i++;
            (*mon3)--;
            fclose(fp);
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
    int count = *monster_number;

     while (1)
     {
         
         int ch = 0,mch =0; 
    


        

         printf("���� ���� : " );


        


         


             
         back:
         for (int i = 0; i < *monster_number; i++) 
         {
             if (buffer_m[i][0] <= 0)
             {
                 continue;
             }
             printf("%d.���� ", i + 1);
         }
            
          
        
         
         scanf("%d", &mch);
        
         if (buffer_m[mch - 1][0] <= 0)
         {
             
             printf("����� ���ʹ� �����Ҽ������ϴ�!\n");
             goto back;

         }
             
         printf("1.����\n");// 1. ���� 2.��ų 3.������ ��� ��� �߰� �� ����...
         scanf("%d", &ch); // �����Է�


         

         if (ch == 1)
         {
             printf("palyer-> monster ����\n");
             buffer_m[mch - 1][0] -= buffer_h[1];//���� ü�¿��� �÷��̾� ���ݷ� ����
             printf("monster ü�� : % d\n ", buffer_m[mch - 1][0]);
             printf("monster-> player ����\n");
             buffer_h[0] -= buffer_m[mch - 1][1]; //�÷��̾� ü�¿��� ���� ���ݷ� ����
             printf("player ü�� : %d\n ", buffer_h[0]);
             ch = 0; //���� �ʱ�ȭ

             if (buffer_m[mch - 1][0] <= 0)
             {

                 buffer_h[3] += buffer_m[mch - 1][2];//��� ȹ��.

                 count--;


             }



             fopen_s(&fp, "hero_status.txt", "w");

             for (int i = 0; i < StatusSize; i++)
                 fprintf(fp, "%d\n", buffer_h[i]);


             fclose(fp);
             system("cls");
             print_status();
             for (int i = 0; i < *monster_number; i++)
             {
                 printf("-------------------monster------------------\n");
                 printf("ü��: %d  ", buffer_m[i][0]);
                 printf("���ݷ�: %d\n", buffer_m[i][1]);
                 printf("���: %d  \n", buffer_m[i][2]);
                 printf("--------------------------------------------\n");
             }
            
         }
         
            
           
            
             if (count <= 0)
             {
                 printf("------------------stage����------------------\n");
                 break;
             }
         

         
         if (buffer_h[0] <= 0) //�÷��̾� ü���� 0���� �̸� ����
         {
             printf("GAME OVER\n");
             return 0;
         }

     }


    
     

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


