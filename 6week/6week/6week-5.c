#include<stdio.h>

int main() {

    /*
     AZ
   + ZA
   -------
     99
     �̹Ƿ� 10A + Z + 10Z + A = 99
     11A + 11Z = 99
     A + Z = 11 �� ���ڸ� ã���� �ȴ�.
     �ݺ����� ��ø ���Ѿ� �ϹǷ�
    */

    printf("A Z\n");
    for (int i = 0; i < 12; i++)
    {
        
        for (int j = 0; j < 12; j++)
        {
            if (i + j == 11)
            {
                printf("%d %d ", i, j);
            }
        }
        printf("\n");

    }

}
