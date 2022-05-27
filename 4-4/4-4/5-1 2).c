#include<stdio.h>

int main() {
	double num1, num2;
	printf("µÎ °³ÀÇ ½Ç¼ö ÀÔ·Â: ");
	
	scanf_s("%lf %lf", &num1, &num2);

	printf("µÎ ¼ö ÀÇ µ¡¼À: %lf \n", num1+num2);
	printf("µÎ ¼ö ÀÇ »¬¼À: %lf \n", num1-num2);
	printf("µÎ ¼ö ÀÇ °ö¼À: %lf \n", num1*num2);
	printf("µÎ ¼ö ÀÇ ³ª´°¼À: %lf \n", num1/num2);

	return 0;
}