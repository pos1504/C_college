#include<stdio.h>


int SearchMaxMin(int arr[], int count) {
	int max = arr[0], min = arr[0] ;
	for (int i = 0; i < count; i++) {
		if (arr[i] > max) max = arr[i];//�ִ밪 ã��
		if (arr[i] < min) min = arr[i];//�ּҰ� ã��

		
	}
	

	printf("�ִ밪 : %d �ּҰ� : %d", max, min);//�ִ� �ּҰ� ���

	return 0;
}

int main() {

	int numArr[3] ;


	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &numArr[i]); //���� 3�� �Է� 
	}

	SearchMaxMin(numArr,sizeof(numArr)/sizeof(int));// �迭�� �迭 ������ ���� 
	
}