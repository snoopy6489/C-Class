#include <stdio.h>
void main() {
	int in = 0;
	printf("Please enter a number\n");
	scanf_s("%d", &in);
	if(in%2==0){
		printf("%d is an even number.\n", in);
	}
	else{
		printf("%d is an odd number.\n", in);
	}
}