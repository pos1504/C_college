#include<stdio.h>

void find_two_largest(int a[], int n, int* largest, int* sec_largest, int* third_largest)
{
	*largest = a[0];
	*sec_largest = a[0];
	*third_largest = a[0];

	for (int i = 1; i < n; i++) 
	{
		if (*largest < a[i])
			*largest = a[i];
	}


	for (int i = 1; i < n; i++)
	{
		if (a[i] < *largest) 
		{
			if (*sec_largest < a[i])
				*sec_largest = a[i];
		}
		
	}

	for (int i = 1; i < n; i++)
	{

		if (a[i] < *sec_largest)
		{
			if (*third_largest < a[i])
				*third_largest = a[i];
		}
	}


}



void test1() 
{
	int arr[3] = { 11,22,33 };
	int* ptr = arr;
	printf("%d %d %d \n", *ptr, *(ptr + 1), *(ptr + 2));


	printf("%d", *ptr); ptr++;
	printf("%d", *ptr); ptr++;
	printf("%d", *ptr); ptr--;
	printf("%d", *ptr); ptr--;
	printf("%d", *ptr); printf("\n");
	return 0;


}


void test2()
{
	char str1[] = "My String";
	char* str2 = "Your String";

	str2 = "Our String";
	printf("%s %s \n", str1, str2);

	str1[0] = 'x';
	str2[0] = 'x';

	printf("%s %s \n", str1, str2);
	return 0;
}


int main() {
	int largest, sec_largest,third_largest;

	int a[] = { 1,11,3,18,8 };

	find_two_largest(a, sizeof(a) / sizeof(a[0]), &largest, &sec_largest, &third_largest);

	printf("함수내 가장큰 값 %d\n", largest);
	printf("함수내 두번쨰로큰 값 %d\n", sec_largest);
	printf("함수내 세번째로큰 값 %d\n", third_largest);

	test1();
}