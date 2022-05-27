#include<stdio.h>

int main() {
	int number1 = 1;// 0이면 안되므로 1로 초기화 
	int sum = 0;//sum초기화
	while ( number1 != 0)// number1이 0이 아닐때 계속 반복
	{
		
		scanf_s("%d", &number1);

		sum += number1; //합을 구하고..
	}

	printf("%d", sum);
	
}