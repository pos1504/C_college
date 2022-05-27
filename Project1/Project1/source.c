#include<stdio.h>
#include<string.h>

int main(void) {
	int maxlength = 0;
	char animals[5][20];
	char *maxanimals= NULL;
	printf("동물 이름 5개 입력: ");
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
	printf("길이가 가장 긴 동물 이름은 %s입니다.",maxanimals);
	printf("\n1921458 정세형");
	return 0;
}