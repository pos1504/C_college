#include<stdio.h>

int main() {
	int i = 0;
	int sum = 0;
	do {
		sum += i;
	
		i += 2;
	} while (i <= 100);

	printf("%d", sum);

}

