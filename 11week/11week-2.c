#include<stdio.h>


int main() 
{
	int num2 = 20, num1 = 10;

	int*ptr1 = &num1, *ptr2 = &num2;

	int* ptr3 = 0;

	ptr1 = &num2;
	ptr2 = &num1;

	printf("ptr1 가리키는 값 : %4d  ptr2 가리키는 값 : %4d\n", *ptr1, *ptr2);
	printf("ptr1 주소 값 : %4d  ptr2 주소 값 : %4d\n", ptr1, ptr2);

}
