#include<stdio.h>


int main() 
{
	int num2 = 20, num1 = 10;

	int*ptr1 = &num1, *ptr2 = &num2;

	printf("*ptr1 : %4d  *ptr2 : %4d\n", *ptr1, *ptr2);
	printf("ptr1  : %4p  ptr2  : %4p\n", ptr1, ptr2);


	*ptr1 += 10; //num1�ǰ� 10 ����
	*ptr2  -= 10;//num2�ǰ� 10 ����



	int *temp;
	temp = ptr1;
	ptr1 = ptr2; //�����ͺ���ptr1��num2������Ŵ
	ptr2 = temp; //�����ͺ���ptr2��num1����Ŵ



	printf("*ptr1 : %4d  *ptr2 : %4d\n", *ptr1, *ptr2);
	printf("ptr1  : %4p  ptr2  : %4p\n", ptr1, ptr2);

}
