#include<stdio.h>


int main() {

	int arr[5] = { 0, };// √ ±‚»≠
	int max = 0, min = 0, sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &arr[i]);


	}

	for (int i = 0; i < 5; i++) {
		max = arr[0];
		min = arr[0];
		if (arr[i] >= max) max = arr[i];

		if (arr[i] <= min) min = arr[i];
		sum += arr[i];


	}
	printf("%d %d %d", max, min, sum);


}