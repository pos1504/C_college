#include<stdio.h>

int main(void) {
	int num;
	printf("줄을 입력하세요 : ");
	scanf_s("%d",&num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d", j+1);
		}
		for (int j = 0; j < num - i - 1; j++) {
			printf("*");
		}
		printf("\n");
	}


	printf("\n\n 1921458 정세형\n");

		return 0;
}