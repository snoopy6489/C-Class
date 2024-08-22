#include <stdio.h>

int main() {
	int num1, num2, sum;
	printf("Enter two numbers ");
	scanf_s("%d", &num1);
	scanf_s("%d", &num2);
	sum = num1 + num2;
	printf("%d+%d=%d\n", num1, num2, sum);
	printf("Sum: %d", sum);
	return 0;
}