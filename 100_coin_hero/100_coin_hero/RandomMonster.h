#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

int RandomMonster()
{
    printf("<몬스터 등장> \n");
    srand(time(NULL));
    int x[5], i, mon1 = 0, mon2 = 0, mon3 = 0;

    int monster_number = rand() % 3 +1;//몬스터 수 랜덤 1~3
    printf("몬스터 수 %d \n", monster_number);
    int* monster = malloc(sizeof(int) * monster_number);


    for (int i = 0; i < monster_number; i++) {
        monster[i] = rand() %3 + 1; //1~3중 랜덤

        if (monster[i] == 1)
            mon1++;
        else if (monster[i] == 2)
            mon2++;
        else if (monster[i] == 3)
            mon3++;
    }
    for (int i = 0; i < monster_number; i++) {
        printf("몬스터 종적 monster[%d] :%d\n",i, monster[i]);
    }
    

    

    
    printf("monster1의 수 :%d\n", mon1);
    printf("monster2의 수 :%d\n", mon2);
    printf("monster3의 수 :%d\n", mon3);

    free(monster);
}

