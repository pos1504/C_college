#include<stdio.h>


int onlynum(float num) {

	int b;

	b = num;// �Ǽ� --> ������ȯ 

	return b;
}

float onlyfloat(float num) {
	float b;
	b = num - (int)num;// �Ǽ����� - �����κ� = �Ǽ��κ�

	return b;

}

int main() {
	float a;//�Ǽ�����
	scanf_s("%f", &a);
	printf("�����κ� %d \n",onlynum(a));
	printf("�Ǽ��κ� %f",onlyfloat(a));
}