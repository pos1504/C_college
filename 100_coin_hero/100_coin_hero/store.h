#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
void print_status();
void fight();

void store()
{
	system("cls");

	int buffer[StatusSize] = { 0 };
	FILE* fp;
	fopen_s(&fp, "hero_status.txt", "r"); //��� status ���� �б�

	if (fp == NULL)
	{
		printf("���� �ε� ����\n");
		return 1;
	}
	for (int i = 0; i < StatusSize; i++)
	{
		fscanf(fp, "%d", &buffer[i]);

	}
	fclose(fp);
	printf("-------------------player-------------------\n");
	printf("ü��: %d  ", buffer[0]);
	printf("���ݷ�: %d\n", buffer[1]);
	printf("����: %d  ", buffer[2]);
	printf("���: %d\n", buffer[3]);
	printf("ü�� ȸ�� ����: %d\n", buffer[4]);
	printf("���ݷ� ��ȭ ����: %d\n", buffer[5]);
	printf("--------------------------------------------\n");

	printf("-------------------stage%d-------------------\n", buffer[9] + 1);//buffer[9]�� stage �ܰ�����
	printf("===============����===============\n"); // ����
	printf("(1) ü�� ȸ�� ���� - 2���\n");
	printf("(2) ���ݷ� ��ȭ ���� - 4���\n");
	printf("==================================\n");

	int count1 = 0; int count2 = 0; // count1: ü�� ȸ�� ���� ��, count2: ���ݷ� ��ȭ ���� ��
	int gold = buffer[3]; // buffer[3]�� �ִ� ��尪 �޾ƿ�

	printf("ü�� ȸ�� ������ �� �� �����Ͻðڽ��ϱ�?\n");
	scanf("%d", &count1);
		if (gold-2*count1 >= 0) {
			printf("ü�� ȸ�� ����: %d��\n", count1);
			gold -= 2 * count1;
			printf("���� ���: %d \n", gold);
		}
		else {
			printf("��尡 �����մϴ�.\n");
			count1 = 0; // ��� ����-> �Է¹��� count�� 0���� ���
			
		}
	
	printf("���ݷ� ��ȭ ������ �� �� �����Ͻðڽ��ϱ�?\n");
	scanf("%d", &count2);
		if (gold-4*count2 >= 0) {
			printf("���ݷ� ȸ�� ����: %d�� \n", count2);
			gold -= 4 * count2;
			printf("���� ���: %d\n", gold);
		}
		else {
			printf("��尡 �����մϴ�.\n"); // ��� ����-> �Է¹��� count�� 0���� ���
			count2 = 0;
			
		}
		

	buffer[3] = gold;
	buffer[4] += count1;
	buffer[5] += count2;
	buffer[9] += 1; //stage num ����.
	
	printf("-------------------player-------------------\n");
	printf("ü��: %d  ", buffer[0]);
	printf("���ݷ�: %d\n", buffer[1]);
	printf("����: %d  ", buffer[2]);
	printf("���: %d\n", buffer[3]);
	printf("ü�� ȸ�� ����: %d\n", buffer[4]);
	printf("���ݷ� ��ȭ ����: %d\n", buffer[5]);
	printf("--------------------------------------------\n");
	

	fopen_s(&fp, "hero_status.txt", "w");

	for (int i = 0; i < StatusSize; i++)
		fprintf(fp, "%d\n", buffer[i]);


	fclose(fp);
}