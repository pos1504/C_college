#include<stdio.h>

int main() {
	int number1 = 1;// 0�̸� �ȵǹǷ� 1�� �ʱ�ȭ 
	int sum = 0;//sum�ʱ�ȭ
	while ( number1 != 0)// number1�� 0�� �ƴҶ� ��� �ݺ�
	{
		
		scanf_s("%d", &number1);

		sum += number1; //���� ���ϰ�..
	}

	printf("%d", sum);
	
}