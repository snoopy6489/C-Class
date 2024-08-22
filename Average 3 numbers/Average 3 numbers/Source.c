#include <stdio.h>
void main(){
	float n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	printf("Please enter number 1.\n");
	scanf_s("%f", &n1);
	printf("Please enter number 2.\n");
	scanf_s("%f", &n2);
	printf("Please enter number 3.\n");
	scanf_s("%f", &n3);
	n4 = (n1 + n2 + n3)/3;
	printf("The average is %f \n", n4);
}