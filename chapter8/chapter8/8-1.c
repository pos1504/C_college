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

	printf("���� �Է�: ");
	scanf_s("%d", &num);

	if (num < 0)
		printf("�Է� ���� 0���� �۴�. \n");
	if (num > 0)
		printf("�Է� ���� 0���� ũ��. \n");
	if (num == 0)
		printf("�Է� ���� 0�̴�. \n");
}

int test2() {
	int num;
	printf("���� �Է�: ");
	scanf_s("%d", &num);
	if (num < 0)
		printf("�Է� ���� 0���� �۴�. \n");
	else
		printf("�Է� ���� 0���� ���� �ʴ�. \n");

}

int test3() {
	int opt;
	double num1, num2;
	double result;
	printf("1.���� 2.���� 3.���� 4.������ \n");
	printf("����? ");
	scanf_s("%d", &opt);
	printf("�ΰ��� �Ǽ��� �Է�: ");
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

	printf("���: %f \n", result);

}

int test4() {
	int num, abs;
	printf("���� �Է�");
	scanf_s("%d", &num);
	abs = (num > 0) ? num : -num;
	printf("���밪: %d \n", abs);
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
	printf("1�̻� 5������ ���� �Է�: ");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:
		printf("1�� one");
		break;
	case 2:
		printf("2�� two");
		break;
	case 3:
		printf("3�� three");
		break;

	case 4:
		printf("4�� four");
		break;
	case 5:
		printf("5�� five");
		break;
	default:
		printf("I don't know \n");

	}
}

	int test8() {
		int num;
		printf("�ڿ��� �Է�: ");
		scanf_s("%d",&num);

		if (num == 1)
			goto ONE;
		else if (num == 2)
			goto TWO;
		else
			goto OTHER;

	ONE:
		printf("1�� �Է��ϼ̽��ϴ�! \n");
		goto END;
	TWO:
		printf("2�� �Է��ϼ̽��ϴ�! \n");
		goto END;
	OTHER:
		printf("3�� �Է��ϼ̽��ϴ�! \n");
		goto END;

	END:
		return 0;
	}



















