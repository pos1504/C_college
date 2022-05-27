#include<stdio.h>

int main() {
	


	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
}

int test1() {
	int num;

	printf("정수 입력: ");
	scanf_s("%d", &num);

	if (num < 0)
		printf("입력 값은 0보다 작다. \n");
	if (num > 0)
		printf("입력 값은 0보다 크다. \n");
	if (num == 0)
		printf("입력 값은 0이다. \n");
}

int test2() {
	int num;
	printf("정수 입력: ");
	scanf_s("%d", &num);
	if (num < 0)
		printf("입력 값은 0보다 작다. \n");
	else
		printf("입력 값은 0보다 작지 않다. \n");

}

int test3() {
	int opt;
	double num1, num2;
	double result;
	printf("1.뎃셈 2.뺄셈 3.곱셈 4.나눗셈 \n");
	printf("선택? ");
	scanf_s("%d", &opt);
	printf("두개의 실수를 입력: ");
	scanf_s("%lf %lf", &num1, &num2);

	if (opt == 1) {
		result = num1 + num2;
	}
	else if (opt == 2) {
		result = num1 - num2;
	}
	else if (opt == 3) {
		result = num1 * num2;
	}
	else {
		result = num1 / num2;
	}

	printf("결과: %f \n", result);

}

int test4() {
	int num, abs;
	printf("정수 입력");
	scanf_s("%d", &num);
	abs = (num > 0) ? num : -num;
	printf("절대값: %d \n", abs);
}

int test5() {
	int sum = 0, num = 0;
	while (1) {
		sum += num;
		if (sum > 5000)
			break;
		num++;

	}

	printf("sum: %d \n", sum);
	printf("num: %d \n", num);
}

int test6() {
	int num;
	printf("start!");
	for (num = 1; num < 20; num++) {
		if (num % 2 == 0 || num % 3 == 0)
			continue;
		printf("%d", num);

	}
	printf("end! \n");
}

int test7() {
	int num;
	printf("1이상 5이하의 정수 입력: ");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
		printf("1은 one");
		break;
	case 2:
		printf("2는 two");
		break;
	case 3:
		printf("3은 three");
		break;

	case 4:
		printf("4는 four");
		break;
	case 5:
		printf("5는 five");
		break;
	default:
		printf("I don't know \n");

	}
}

	int test8() {
		int num;
		printf("자연수 입력: ");
		scanf_s("%d",&num);

		if (num == 1)
			goto ONE;
		else if (num == 2)
			goto TWO;
		else
			goto OTHER;

	ONE:
		printf("1을 입력하셨습니다! \n");
		goto END;
	TWO:
		printf("2을 입력하셨습니다! \n");
		goto END;
	OTHER:
		printf("3을 입력하셨습니다! \n");
		goto END;

	END:
		return 0;
	}



















