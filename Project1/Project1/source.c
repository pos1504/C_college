#include<stdio.h>
#include<string.h>

int main(void) {
	int maxlength = 0;
	char animals[5][20];
	char *maxanimals= NULL;
	printf("���� �̸� 5�� �Է�: ");
	for (int i = 0; i < 5; i++)
		scanf_s("%s",animals[i],20);
	for (int i = 0; i < 5; i++)
	{
		if (maxlength < strlen(animals[i]))
		{
			maxlength = strlen(animals[i]);
			maxanimals = animals[i];
		}
	}
	printf("���̰� ���� �� ���� �̸��� %s�Դϴ�.",maxanimals);
	printf("\n1921458 ������");
	return 0;
}