#include<stdio.h>

int main() {
	int input,change = 0; //������ �Է°�(���Ұ�),�Ž�����
	int won[4] = {50000,10000,5000,1000};// won[0]: ������,won[1]: ���� ,won[2]: ��õ�� ,won[3]: õ��   
	int woncount[4] = { 0 };//������ �������
	printf("������ ���Ұ��� �Է��Ͻÿ�. :");
	scanf_s("%d", &input);

		for (int i = 0; i < sizeof(won)/sizeof(int) ; i++) // ����������� ��ŭ �ݺ� 
		{
			
			woncount[i] = input / won[i];//i��°������� ����
			input = input%won[i];//i��° ������� ��� �� ���� ���Ұ� ���
		}
		
		
		change = input;// ���Ҹ��� ������ �� ���� ��� 600�� 500��..
		if (change != 0)//������ ���� 0���� �ƴϸ�
		{
			woncount[3]++; //������ ���� �ּҴ����� õ������ ���� 
			change = won[3] - change; // �Ž�����
		}	 
	
	for (int i = 0; i < 4; i++)
		printf("�����%d�� : %d�� \n",won[i],woncount[i]);
	printf("�Ž����� : %d��\n", change);
	printf("1921458������");
	return 0;
};
