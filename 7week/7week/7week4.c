#include<stdio.h>

int squared(int n) {
	static int num = 1; // num���� �ʱ�ȭ �����ʵ��� ����
	if (n <= 0) return; // Ż������

	num = 2 * num; //2�� ����
	squared(n - 1); //�Լ� �ݺ�

	return num;
}


int main(void) {
	int n;
	printf("�����Է�: ");
	scanf_s("%d", &n);
	

	printf("2�� %d���� %d",n, squared(n));
}