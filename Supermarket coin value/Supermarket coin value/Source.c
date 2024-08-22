#include <stdio.h>
void main()
{
	float Q = 0, N=0,Di=0, P=0, T=0, D = 0;
	printf("Please enter the number of Dollars you have\n");
	scanf_s("%f", &D);
	printf("Please enter the number of Quarters you have\n");
	scanf_s("%f", &Q);
	printf("Please enter the number of Dimes you have\n");
	scanf_s("%f", &Di);
	printf("Please enter the number of Nickles you have\n");
	scanf_s("%f", &N);
	printf("Please enter the number of Pennies you have\n");
	scanf_s("%f", &P);
	P = P * .01;
	Q = Q * .25;
	N = N * .05;
	Di = Di * .1;
	T = D + Q + N + Di + P;
	printf("Total value: %.2f\n", T);
}