

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
	


        int** buffer_m = (int**)malloc(sizeof(int*) * (*monster_number)); //몬스터들 status를 받기 위한 이중배열
        for (int i = 0; i < *monster_number; i++) {
            buffer_m[i] = (int*)malloc(sizeof(int) * monsterSize);
        }



        int buffer_h[StatusSize] = { 0, }; //player 체력 공격력 마나 골드량 받기위한 buffer
        FILE* fp;

        int i = 0;
        int j = 0;
        while (i < *monster_number)   //몬스터 수만큼 반복 
        {
            for (int j = 0; j < 10; j++) 
            {
                if (mon[j].mon > 0) //몬스터 종류 있을때  일때
                {
                    fopen_s(&fp, "monster_list.txt", "r");  //player status 불러오기

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
                    i++; //몬스터 수 
                    fclose(fp);
                
                    
                }
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
        int count = *monster_number; //종료하기 위한 count 선언
        int ch = 0; //ch 공격 선택 
        while (1)
        {

            int mch = 0;// mch몬스터 선택






            printf("몬스터 선택 : ");


        back:
            for (int i = 0; i < *monster_number; i++)
            {
                if (buffer_m[i][0] <= 0)//몬스터가 죽으면..
                {
                    continue;
                }
                printf("%d.몬스터 ", i + 1);
                
            }

            


            scanf("%d", &mch);
            
            if (mch > *monster_number) {
                printf("올바른 숫자를 입력하세요\n");
                goto back;
            }
            if (buffer_m[mch - 1][0] <= 0)
            {

                printf("사망한 몬스터는 선택할수없습니다!\n");
                goto back; //다른숫자를 선택하면... 돌아가기

            }

            printf("1.공격\n2.스킬(마나4소모)\n3.아이템 사용\n"); //1. 공격 2.스킬 3.아이템 사용 등등 추가
            scanf("%d", &ch); // 숫자입력




            if (ch == 1)
            {

                printf("palyer-> monster 공격\n");
                buffer_m[mch - 1][0] -= buffer_h[1];//몬스터 체력에서 플레이어 공격력 빼기
                printf("monster 체력 : % d\n ", buffer_m[mch - 1][0]);
                Sleep(1000);
                printf("monster-> player 공격\n");
                buffer_h[0] -= buffer_m[mch - 1][1]; //플레이어 체력에서 몬스터 공격력 빼기
                printf("player 체력 : %d\n ", buffer_h[0]);
                Sleep(1000);
                ch = 0; //숫자 초기화

                if (buffer_h[1] > buffer_h[7])
                {
                    buffer_h[1] = buffer_h[7]; //때리고 물약효과 없애기
                }


                if (buffer_m[mch - 1][0] <= 0)
                {

                    buffer_h[3] += buffer_m[mch - 1][2];//몬스터 골드 획득 골드 획득.

                    count--;


                }



                fopen_s(&fp, "hero_status.txt", "w");

                for (int i = 0; i < StatusSize; i++)
                    fprintf(fp, "%d\n", buffer_h[i]);


                fclose(fp);




            }

            if (ch == 2) //스킬 사용
            {
                buffer_h[2] -= 4;

                if (buffer_h[2] < 0)
                {
                    printf("마나가 없습니다 다시선택해주세요.\n");
                    buffer_h[2] += 4;
                    ch = 0;
                    Sleep(1000);
                }
                else
                {
                    printf("palyer-> monster 전부공격\n");
                    for (int i = 0; i < *monster_number; i++)
                    {
                        buffer_m[i][0] -= buffer_h[1];
                        printf("monster%d 체력 : %d\n ", i, buffer_m[i][0]);
                    }
                    buffer_h[0] -= buffer_m[mch - 1][1]; //플레이어 체력에서 몬스터 공격력 빼기
                    printf("player 체력 : %d\n ", buffer_h[0]);
                    Sleep(1000);

                    if (buffer_h[1] > buffer_h[7])
                    {
                        buffer_h[1] = buffer_h[7]; //때리고 물약효과 없애기
                    }


                    for (int i = 0; i < *monster_number; i++)
                    {
                        if (buffer_m[i][0] <= 0)
                        {
                            buffer_h[3] += buffer_m[i][2];//몬스터 골드 획득 골드 획득.
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

            if (ch == 3) //아이템 사용
            {

                int pot = 0;

                printf("1. 체력 회복 포션 사용\n2. 공격력 강화 포션 사용\n3.마나 회복 포션 사용\n4.나가기");
                scanf("%d", &pot);
                if (pot == 1)
                {
                    if (buffer_h[4] > 0)
                    {
                        buffer_h[4] -= 1;
                        buffer_h[0] += 10; //체력 10 증가
                        printf("monster-> player 공격\n");
                        buffer_h[0] -= buffer_m[mch - 1][1]; //플레이어 체력에서 몬스터 공격력 빼기
                        printf("player 체력 : %d\n ", buffer_h[0]);
                        Sleep(1000);
                    }
                    else {

                        printf("아이템이 없습니다 다시 선택해주세요. \n");
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
                        buffer_h[1] += 5; //공격력 5 증가
                        printf("monster-> player 공격\n");
                        buffer_h[0] -= buffer_m[mch - 1][1]; //플레이어 체력에서 몬스터 공격력 빼기
                        printf("player 체력 : %d\n ", buffer_h[0]);
                        Sleep(1000);
                    }
                    else {
                        printf("아이템이 없습니다 다시 선택해주세요. \n");
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
                        buffer_h[2] += 8; //마나 8 증가
                        printf("monster-> player 공격\n");
                        buffer_h[0] -= buffer_m[mch - 1][1]; //플레이어 체력에서 몬스터 공격력 빼기
                        printf("player 체력 : %d\n ", buffer_h[0]);
                        Sleep(1000);
                    }
                    else {
                        printf("아이템이 없습니다 다시 선택해주세요. \n");
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
            printf("-------------------stage%d-------------------\n", buffer_h[9] + 1);//buffer[9]에 stage 단계저장
            for (int i = 0; i < *monster_number; i++)
            {
                printf("-------------------monster------------------\n");
                printf("체력: %d  ", buffer_m[i][0]);
                printf("공격력: %d\n", buffer_m[i][1]);
                printf("골드: %d  \n", buffer_m[i][2]);
                printf("--------------------------------------------\n");
            }

            if (count <= 0)
            {
                printf("------------------stage종료------------------\n"); //종료 구문
                break;
            }



            if (buffer_h[0] <= 0) //플레이어 체력이 0이하 이면 종료
            {
                printf("GAME OVER\n");
                return 0;
            }

        }


        buffer_h[9] += 1; //stage num 증가.


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


