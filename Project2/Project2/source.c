#include<stdio.h>
#include<float.h>
#include<limits.h>


double squared1(double value[][2], double value2[][2]);
double squared2(double value[][2], double value2[2], double value3[2]);




int main(void) {
	double value[2][2] = { {0.98, 0.02}, {0.05, 0.95} };
	double value2[2][2] = {0, };
	double value3[2][2] = { 0, };
	double answer[2] = { 0, };
	double migration[2] = { 0.5, 0.5};


	int infinite = INT_MAX;
	

	
	squared1(value, value2);



	


	for (int i = 0; i < 10; i++) {
		squared1(value2, value3);
			for (int i = 0; i < 2; i++) {

				for (int j = 0; j < 2; j++)
					value2[i][j] = 0;
			}
		squared1(value3, value2);
			for (int i = 0; i < 2; i++) {

				for (int j = 0; j < 2; j++)
					value3[i][j] = 0;
			}

	}

	squared2(value2, migration, answer);

	for (int i = 0; i < 2; i++)
		printf("%lf ", answer[i]);

	for (int i = 0; i < 2; i++) {
	
		for (int j = 0; j < 2; j++)
			printf("%lf ", value2[i][j]);
			
		printf("\n");

	}




	return 0;
}




double squared1(double value[][2], double value2[][2])
{


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			
			for (int k = 0; k < 2; k++)
				value2[i][j] += value[i][k] * value[k][j];

		}
	}

	return value2[2][2];

}


double squared2(double value[][2], double value2[2] , double value3[2])
{


	for (int i = 0; i < 2; i++) {
		
			
			for (int k = 0; k < 2; k++)
				value3[i] += value2[k] * value[k][i];

		
	}

	return value3[2];

}