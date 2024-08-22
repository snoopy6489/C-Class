#include <stdio.h>
#define SIZE 15
void main(){
	int A[SIZE];
	for (int i = 0; i < SIZE; i++) {
		printf("Enter A[%d]:",i);
		scanf_s("%d", &A[i]);
	}
	float sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += A[i];
	}
}
