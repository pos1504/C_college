#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

int RandomMonster()
{
    printf("<몬스터 등장> \n");
    srand(time(NULL));
    int x[5], i, mon1 = 0, mon2 = 0, mon3 = 0;

    for (i = 0; i < 5; i++) // 몬스터의 수: 5
    {
        x[i] = rand() % 3 + 1; // 1~3 중 랜덤
        if (x[i] == 1)
            mon1++;
        else if (x[i] == 2)
            mon2++;
        else if (x[i] == 3)
            mon3++;

        printf("%d\n", x[i]);
    }
    printf("monster1의 수 :%d\n", mon1);
    printf("monster2의 수 :%d\n", mon2);
    printf("monster3의 수 :%d\n", mon3);
}

