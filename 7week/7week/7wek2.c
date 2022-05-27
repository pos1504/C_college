#include<stdio.h>


int onlynum(float num) {

	int b;

	b = num;// 실수 --> 정수변환 

	return b;
}

float onlyfloat(float num) {
	float b;
	b = num - (int)num;// 실수인자 - 정수부분 = 실수부분

	return b;

}

int main() {
	float a;//실수인자
	scanf_s("%f", &a);
	printf("정수부분 %d \n",onlynum(a));
	printf("실수부분 %f",onlyfloat(a));
}