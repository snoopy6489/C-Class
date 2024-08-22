#include <stdio.h>
void main() {
	int n1 = 0, n2 = 0, n3 = 0, fn = 0;
	printf("Please enter number 1.\n");
	scanf_s("%d", &n1);
	printf("Please enter number 2.\n");
	scanf_s("%d", &n2);
	printf("Please enter number 3.\n");
	scanf_s("%d", &n3);
	/*if (n1 > n2) {
		printf("The largest number was %d", n1);

	}
	printf("The largest number was %d", n2);*/
	if (n1 >= n2 && n1 >= n3) {
		printf("max= %d", n1);
	}
	if (n2 >= n1 && n2 >= n3) {
		printf("max= %d", n2);
	}
	if (n3 >= n2 && n3 >= n1) {
		printf("max= %d", n3);
	}
}
/*
int max=n1
if(n2>max);
	max=n2;
if(n3>max);
	max=n3;
printf("max=&d,max);
*/