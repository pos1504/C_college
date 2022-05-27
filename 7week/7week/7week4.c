#include<stdio.h>

int squared(int n) {
	static int num = 1; // num값이 초기화 되지않도록 고정
	if (n <= 0) return; // 탈출조건

	num = 2 * num; //2의 제곱
	squared(n - 1); //함수 반복

	return num;
}


int main(void) {
	int n;
	printf("정수입력: ");
	scanf_s("%d", &n);
	

	printf("2의 %d승은 %d",n, squared(n));
}