#include<stdio.h>

int main() {
	double num1, num2;
	printf("�� ���� �Ǽ� �Է�: ");
	
	scanf_s("%lf %lf", &num1, &num2);

	printf("�� �� �� ����: %lf \n", num1+num2);
	printf("�� �� �� ����: %lf \n", num1-num2);
	printf("�� �� �� ����: %lf \n", num1*num2);
	printf("�� �� �� ������: %lf \n", num1/num2);

	return 0;
}