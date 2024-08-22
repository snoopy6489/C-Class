#include<stdio.h>
/*
void main() {
	int grade = 0;
	printf("Please input a grade.\n");
	scanf_s("%d", &grade);
	if (grade >= 90) {
		printf("A");
	}
	else if (grade >= 80) {
		printf("B");
	}
	else if (grade >= 70) {
		printf("C");
	}
	else if (grade >= 60) {
		printf("D");
	}
	else {
		printf("F");
	}
}
*/
void main() {
	int grade = 0;
	printf("Please input a grade.\n");
	scanf_s("%d", &grade);
	switch (grade/10)
	{
	case 10:
	case 9:
		printf("A");
		break;
	case 8:
		printf("B");
		break;
	case 7:
		printf("C");
		break;
	case 6:
		printf("D");
		break;
	default:
		printf("F");
		break;
	}
}