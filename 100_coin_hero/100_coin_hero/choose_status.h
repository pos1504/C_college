
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
void choose_status()
{
	int num;
	printf("ĳ���͸� �����ϼ���.\n 1. �˻�\n");//���� �߰� ����
	scanf("%d", &num);
	if (num == 1)
	{
		FILE* fp = fopen("hero_status.txt", "w"); //��� status ������ ����

		int hero_status[MAX] = { 20,2,10,5 }; //�˻� status 
		for (int i = 0; i < MAX; i++)
			fprintf(fp, "%d\n", hero_status[i]); //0.ü�� 1.���ݷ� 2.���� 3.��差 4.... 9.



		fclose(fp);
	}



	FILE* fp = fopen("hero_status.txt", "r");  //��� status ������ �б�

	int buffer[MAX] = { 0, };

	int i;


	for (i = 0; i < MAX; i++) // �迭�� ũ�⸸ŭ ���� �Է� ����

	{

		fscanf(fp, "%d", &buffer[i]);

	}


	fclose(fp); // �Է��� �����ڿ� ���ϴݱ�



	for (i = 0; i < 10; i++) // �Է¹��� �迭�� ���

	{

		printf("data[%d] : %d \n", i, buffer[i]);

	}





}
