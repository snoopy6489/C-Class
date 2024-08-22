#include <stdio.h>
void main()
{
	int x = 0;
	int x2 = 0;
	int x3 = 0;
	int fx = 0;
	printf("Enter a variable\n");
	scanf_s("%d", &x);
	x2 = x*x;
	x3 = x*3;
	fx = x2+x3;
	printf("Results: %d\n",fx );
}