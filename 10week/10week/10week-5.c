#include<stdio.h>
int record[5][5]; //���������� �ʱ�ȭ X

void  Wrecord() {
	
	
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;
		printf("%d��° �л� �����Է� \n", i + 1);
		for (int j = 0; j < 4; j++)
		{
			scanf_s("%d", &record[i][j]);  
			sum += record[i][j];
		}
		record[i][4] = sum;  //%d�л� �����հ� ����
	}
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;

		for (int j = 0; j < 4; j++)
		{

			sum += record[j][i];
			record[4][i] = sum;  //���� �����հ� ����
		}
		record[4][4] += sum; //���� ���� ����
	}


}
int main() {
	

	Wrecord();
	
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;

		for (int j = 0; j < 5; j++)
		{
			printf("%3d", record[i][j]); //�迭���
			
		}
		printf("\n");
	}
}
	
