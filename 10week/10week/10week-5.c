#include<stdio.h>
int record[5][5]; //전역변수는 초기화 X

void  Wrecord() {
	
	
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;
		printf("%d번째 학생 성적입력 \n", i + 1);
		for (int j = 0; j < 4; j++)
		{
			scanf_s("%d", &record[i][j]);  
			sum += record[i][j];
		}
		record[i][4] = sum;  //%d학생 성적합계 저장
	}
	for (int i = 0; i < 4; i++)
	{
		int sum = 0;

		for (int j = 0; j < 4; j++)
		{

			sum += record[j][i];
			record[4][i] = sum;  //과목 성적합계 저장
		}
		record[4][4] += sum; //과목별 총점 저장
	}


}
int main() {
	

	Wrecord();
	
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;

		for (int j = 0; j < 5; j++)
		{
			printf("%3d", record[i][j]); //배열출력
			
		}
		printf("\n");
	}
}
	
