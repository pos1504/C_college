#include<stdio.h>


int SearchMaxMin(int arr[], int count) {
	int max = arr[0], min = arr[0] ;
	for (int i = 0; i < count; i++) {
		if (arr[i] > max) max = arr[i];//최대값 찾기
		if (arr[i] < min) min = arr[i];//최소값 찾기

		
	}
	

	printf("최대값 : %d 최소값 : %d", max, min);//최대 최소값 출력

	return 0;
}

int main() {

	int numArr[3] ;


	for (int i = 0; i < 3; i++) {
		scanf_s("%d", &numArr[i]); //정수 3개 입력 
	}

	SearchMaxMin(numArr,sizeof(numArr)/sizeof(int));// 배열과 배열 개수를 넣음 
	
}