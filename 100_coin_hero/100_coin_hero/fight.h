
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
#define monsterSize 3
void print_status();




void fight(int *monster_number, int* mon1, int* mon2, int* mon3)  // fight함수를 구현을 위해 RandomMonster에서 값을 받아와야 되는데 추후 추가예정
{




    int** buffer_m = (int**)malloc(sizeof(int*) * (*monster_number)); //몬스터들 status를 받기 위한 이중배열
    for (int i = 0; i < *monster_number; i++) {
        buffer_m[i] = (int*)malloc(sizeof(int) * monsterSize); 
    }



    int buffer_h[StatusSize] = { 0, }; //player 체력 공격력 마나 골드량 받기위한 buffer


    FILE* fp;
    int i = 0;
    while (i < *monster_number)   //몬스터 수만큼 반복 
    {
        
        
        if (*mon1 > 0) //몬스터 종류1 일때
        {

            fopen_s(&fp, "monster1_status.txt", "r"); //monster 1 txt 열기 

            if (fp == NULL)
            {
                printf("게임 로딩 실패\n");
                return 1;
            }
            
                for (int j = 0; j < 3; j++)
                {
                    fscanf(fp, "%d", &buffer_m[i][j]); //체력 공격력 골드량 불러오기
                }

            
            (*mon1)--;
            i++;
            fclose(fp);
        }

        else if (*mon2 > 0) //몬스터 종류 1일때
        {
            fopen_s(&fp, "monster2_status.txt", "r"); //monster 1 txt 열기 
            if (fp == NULL)
            {
                printf("게임 로딩 실패\n");
                return 1;
            }


                for (int j = 0; j < 3; j++)
                {
                    fscanf(fp, "%d", &buffer_m[i][j]); //체력 공격력 골드량 불러오기
                }

             i++;
            (*mon2)--;
            fclose(fp);
        }

        else
        {
            fopen_s(&fp, "monster3_status.txt", "r"); //monster 2 txt 열기 

            if (fp == NULL)
            {
                printf("게임 로딩 실패\n");
                return 1;
            }

            
                for (int j = 0; j < 3; j++)
                {
                    fscanf(fp, "%d", &buffer_m[i][j]); //체력 공격력 골드량 불러오기
                }

            i++;
            (*mon3)--;
            fclose(fp);
        }
    };




    fopen_s(&fp, "hero_status.txt", "r");  //player status 불러오기
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
    몬스터 배열 확인
    */
    int count = *monster_number;

     while (1)
     {
         
         int ch = 0,mch =0; 
    


        

         printf("몬스터 선택 : " );


        


         


             
         back:
         for (int i = 0; i < *monster_number; i++) 
         {
             if (buffer_m[i][0] <= 0)
             {
                 continue;
             }
             printf("%d.몬스터 ", i + 1);
         }
            
          
        
         
         scanf("%d", &mch);
        
         if (buffer_m[mch - 1][0] <= 0)
         {
             
             printf("사망한 몬스터는 선택할수없습니다!\n");
             goto back;

         }
             
         printf("1.공격\n");// 1. 공격 2.스킬 3.아이템 사용 등등 추가 할 예정...
         scanf("%d", &ch); // 숫자입력


         

         if (ch == 1)
         {
             printf("palyer-> monster 공격\n");
             buffer_m[mch - 1][0] -= buffer_h[1];//몬스터 체력에서 플레이어 공격력 빼기
             printf("monster 체력 : % d\n ", buffer_m[mch - 1][0]);
             printf("monster-> player 공격\n");
             buffer_h[0] -= buffer_m[mch - 1][1]; //플레이어 체력에서 몬스터 공격력 빼기
             printf("player 체력 : %d\n ", buffer_h[0]);
             ch = 0; //숫자 초기화

             if (buffer_m[mch - 1][0] <= 0)
             {

                 buffer_h[3] += buffer_m[mch - 1][2];//골드 획득.

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
                 printf("체력: %d  ", buffer_m[i][0]);
                 printf("공격력: %d\n", buffer_m[i][1]);
                 printf("골드: %d  \n", buffer_m[i][2]);
                 printf("--------------------------------------------\n");
             }
            
         }
         
            
           
            
             if (count <= 0)
             {
                 printf("------------------stage종료------------------\n");
                 break;
             }
         

         
         if (buffer_h[0] <= 0) //플레이어 체력이 0이하 이면 종료
         {
             printf("GAME OVER\n");
             return 0;
         }

     }


    
     

    fopen_s(&fp, "hero_status.txt", "w");

    for (int i = 0; i < StatusSize; i++)
        fprintf(fp, "%d\n", buffer_h[i]);


    fclose(fp);






    for (int i = 0; i < *monster_number; i++)  //동적메모리 해제
    {
        free(buffer_m[i]);
    }
    free(buffer_m);



}


