#include <stdio.h>


int main(void) {

	int num;

	printf("���� �Է�: ");
	scanf_s("%d", &num);
	num = ~num;
	num = num + 1;
	printf("��ȣ�� �ٲ� ���: %d \n", num);

	return 0;


}
