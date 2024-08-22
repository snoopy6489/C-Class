#include <stdio.h>
void main() {
	float in = 0;
	printf("Please enter a number\n");
	scanf_s("%f", &in);
	if (in < 0) {
		printf("You entered a Negative number.\n");
	}
	else
	{
		printf("you entered a postive number.\n");
	}
}