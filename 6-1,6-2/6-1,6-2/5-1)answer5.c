#include<stdio.h>

int main() {
	int n = 0; // n! 해줄겁니다.. 0으로 초기화
	int factorial = 1; // 팩토리얼은 곱해줘야 되니 1로 초기화...

	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		factorial *= i;//곱하자! 팩토리얼!
	}
	printf("%d", factorial);
}