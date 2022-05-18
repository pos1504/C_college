
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10
void choose_status()
{
	system("cls");//화면지우기

	int num;
	printf("캐릭터를 선택하세요.\n");
	printf("1. 검사   2.법사   3.도적 \n");
	scanf("%d", &num);
	if (num == 1)
	{
		FILE* fp = fopen("hero_status.txt", "w"); //용사 status 파일을 쓰기

		int hero_status[StatusSize] = { 20,2,10,5 }; //검사 status 
		for (int i = 0; i < StatusSize; i++)
			fprintf(fp, "%d\n", hero_status[i]); //0.체력 1.공격력 2.마나 3.골드량 4.... 9.



		fclose(fp);
	}

	if (num == 2)
	{
		FILE* fp = fopen("hero_status.txt", "w"); 

		int hero_status[StatusSize] = { 17,1,20,5 };  
		for (int i = 0; i < StatusSize; i++)
			fprintf(fp, "%d\n", hero_status[i]); 



		fclose(fp);
	}

	if (num == 3)
	{
		FILE* fp = fopen("hero_status.txt", "w"); 

		int hero_status[StatusSize] = { 18,3,12,5 }; //도적 status 
		for (int i = 0; i < StatusSize; i++)
			fprintf(fp, "%d\n", hero_status[i]); 



		fclose(fp);
	}
	system("cls");//화면지우기

	/*FILE* fp = fopen("hero_status.txt", "r");  //용사 status 파일을 읽기

	int buffer[StatusSize] = { 0, };

	int i;


	for (i = 0; i < StatusSize ; i++) // 배열의 크기만큼 값을 입력 받음

	{

		fscanf(fp, "%d", &buffer[i]);

	}


	fclose(fp); // 입력을 받은뒤에 파일닫기



	for (i = 0; i < 10; i++) // 입력받은 배열을 출력

	{

		printf("data[%d] : %d \n", i, buffer[i]);

	}


     */


}
