#include<stdio.h>

int main() {

    /*
    for (int i = 1; i < 10; i += 2) {
        for (int j = 1; j < i + 1; j++) {
            printf("%d*%d = %d ", i, j, i * j);
        }
        printf("\n");
    }

    */


    for (int i = 1; i < 10; i++) 
    {
        if (i % 2 == 0)       //¦���� ����
            continue;
        for (int j = 1; j < i + 1; j++)
        {
            if (j > i) // i���� ũ�� for�� Ż��!
                break;
            printf("%d*%d = %d ", i, j, i * j);  //������ �� ���
        }
        printf("\n");  

    }

    }
