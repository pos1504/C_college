#include<stdio.h>

int main() {
	int n = 0; // n! ���̴ٰϴ�.. 0���� �ʱ�ȭ
	int factorial = 1; // ���丮���� ������� �Ǵ� 1�� �ʱ�ȭ...

	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		factorial *= i;//������! ���丮��!
	}
	printf("%d", factorial);
}