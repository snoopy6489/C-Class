#include <stdio.h>
int main(void) {
	int a = 7;
	int* aPtr = &a;
	printf("Address of a is %p\nValue of aPtr is %d\n\n", &a, aPtr);
	printf("Value of a is %d\nValue of aPtr is %d\n\n", &a, aPtr);
	printf("Showing that * and & are complements of each other\n");
	printf("&*aPtr = %p\n*&aPtr =%p\n", &*aPtr, *&aPtr);
	a = 5;
	*aPtr = 3;
	printf("After value changed\n");
	printf("Address of a is %p\nValue of aPtr is %d\n\n", &a, aPtr);
	printf("Value of a is %d\nValue of aPtr is %d\n\n", &a, aPtr);
	printf("Showing that * and & are complements of each other\n");
	printf("&*aPtr = %p\n*&aPtr =%p\n", &*aPtr, *&aPtr);
}