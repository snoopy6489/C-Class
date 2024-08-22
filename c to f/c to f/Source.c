#include<stdio.h>
void main() {
	float c = 0, f = 0;
	printf("Please enter a temperature in celsius\n");
	scanf_s("%f", &c);
	f = 9 / 5.0 * c + 32;
	printf("The converted temperature is %.0f ", f);
}