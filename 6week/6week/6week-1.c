#include<stdio.h>

int main() {
	int a, b ;
	int ans = 0;
	printf("�ΰ��� ���� �Է���?");

	scanf_s("%d %d", &a, &b); //������ �Է¹ޱ�

	ans = (a > b) ? a - b :  b - a;  // if ��� ���� �����ڸ� ��� a�� ũ��  a-b ,b�� �� ũ�ų� ������  b-a

	printf("%d", ans); 
	
}