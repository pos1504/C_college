#include<stdio.h>

int Fibo(int num) {
    int i, num1 = 0, num2 = 1, nextnum;// 0�� 1���� ���� ����.
    
   
    for (i = 1; i <= num; ++i) {
        printf("%d, ", num1);
        nextnum = num1 + num2; //���������� ���� �ΰ��� ��
        num1 = num2;//num1����  ���������� ���� 
        num2 = nextnum;// num2����  ����������  ����
    }


}



int main(void) {

    int num;
    scanf_s("%d", &num);
    Fibo(num);

}