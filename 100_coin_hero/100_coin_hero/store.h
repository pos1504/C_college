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
	printf("(3) ���� ȸ�� ���� - 4���\n");
	printf("==================================\n");
	printf("(4) ���� ������\n");

	int num; // ��ȣ �Է�
	printf("��ȣ�� �Է��ϼ���. \n");
	scanf("%d", &num);

	int count1 = 0; int count2 = 0;  int count3 = 0; // count1: ü�� ȸ�� ���� ��, count2: ���ݷ� ��ȭ ���� �� count3 ����ȸ������.
	int gold = buffer[3]; // buffer[3]�� �ִ� ��尪 �޾ƿ�

	while (1)
	{
		if (num == 0) {
			Sleep(2000);
			system("cls");
			print_status();
			printf("===============����===============\n"); // ����
			printf("(1) ü�� ȸ�� ���� - 2���\n");
			printf("(2) ���ݷ� ��ȭ ���� - 4���\n");
			printf("(3) ���� ȸ�� ���� - 4���\n");
			printf("==================================\n");
			printf("(4) ���� ������\n");

			
			printf("��ȣ�� �Է��ϼ���. \n");
			scanf("%d", &num);
		}
		if (num == 1) {
			
			printf("ü�� ȸ�� ������ �� �� �����Ͻðڽ��ϱ�?\n");
			scanf("%d", &count1);
			if (gold - 2 * count1 >= 0) {
				printf("ü�� ȸ�� ����: %d��\n", count1);
				gold -= 2 * count1;
				printf("���� ���: %d \n", gold);
				num = 0;
			}
			else {
				printf("��尡 �����մϴ�.\n");
				count1 = 0; // ��� ����-> �Է¹��� count�� 0���� ���
				num = 0;
			}
		}
		if (num == 2) {
		
			printf("���ݷ� ��ȭ ������ �� �� �����Ͻðڽ��ϱ�?\n");
			scanf("%d", &count2);
			if (gold - 4 * count2 >= 0) {
				printf("���ݷ� ȸ�� ����: %d�� \n", count2);
				gold -= 4 * count2;
				printf("���� ���: %d\n", gold);
				num = 0;
			}
			else {
				printf("��尡 �����մϴ�.\n"); // ��� ����-> �Է¹��� count�� 0���� ���
				count2 = 0;
				num = 0;
			}
		}
		if (num == 3) {

			printf("���� ȸ�� ������ �� �� �����Ͻðڽ��ϱ�?\n");
			scanf("%d", &count3);
			if (gold - 4 * count3 >= 0) {
				printf("���ݷ� ȸ�� ����: %d�� \n", count3);
				gold -= 4 * count3;
				printf("���� ���: %d\n", gold);
				num = 0;
			}
			else {
				printf("��尡 �����մϴ�.\n"); // ��� ����-> �Է¹��� count�� 0���� ���
				count3 = 0;
				num = 0;
			}
		}



		if (num == 4) {
			printf("������ �����ϴ�.\n");
			break;
		}


		buffer[3] = gold;
		buffer[4] += count1;
		buffer[5] += count2;
		buffer[6] += count3;
		count1 = 0;
		count2 = 0;
		count3 = 0;

		fopen_s(&fp, "hero_status.txt", "w");
		for (int i = 0; i < StatusSize; i++)
			fprintf(fp, "%d\n", buffer[i]);
		fclose(fp);
	}
		

	
	buffer[9] += 1; //stage num ����.

	printf("-------------------player-------------------\n");
	printf("ü��: %d  ", buffer[0]);
	printf("���ݷ�: %d\n", buffer[1]);
	printf("����: %d  ", buffer[2]);
	printf("���: %d\n", buffer[3]);
	printf("ü�� ȸ�� ����: %d\n", buffer[4]);
	printf("���ݷ� ��ȭ ����: %d\n", buffer[5]);
	printf("���� ȸ�� ����: %d\n", buffer[6]);
	printf("--------------------------------------------\n");
	printf("-------------------stage%d-------------------\n", buffer[9] + 1);
	

	fopen_s(&fp, "hero_status.txt", "w");

	for (int i = 0; i < StatusSize; i++)
		fprintf(fp, "%d\n", buffer[i]);


	fclose(fp);


}
