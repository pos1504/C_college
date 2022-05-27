#include<stdio.h>


int main() 
{
	int num2 = 20, num1 = 10;

	int*ptr1 = &num1, *ptr2 = &num2;

	printf("*ptr1 : %4d  *ptr2 : %4d\n", *ptr1, *ptr2);
	printf("ptr1  : %4p  ptr2  : %4p\n", ptr1, ptr2);


	*ptr1 += 10; //num1의값 10 증가
	*ptr2  -= 10;//num2의값 10 감소



	int *temp;
	temp = ptr1;
	ptr1 = ptr2; //포인터변수ptr1이num2를가리킴
	ptr2 = temp; //포인터변수ptr2가num1가르킴



	printf("*ptr1 : %4d  *ptr2 : %4d\n", *ptr1, *ptr2);
	printf("ptr1  : %4p  ptr2  : %4p\n", ptr1, ptr2);

}
