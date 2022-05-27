#include<stdio.h>

int Fibo(int num) {
    int i, num1 = 0, num2 = 1, nextnum;// 0과 1에서 부터 시작.
    
   
    for (i = 1; i <= num; ++i) {
        printf("%d, ", num1);
        nextnum = num1 + num2; //다음수열은 이전 두값의 합
        num1 = num2;//num1값을  다음항으로 지정 
        num2 = nextnum;// num2값을  다음항으로  지정
    }


}



int main(void) {

    int num;
    scanf_s("%d", &num);
    Fibo(num);

}