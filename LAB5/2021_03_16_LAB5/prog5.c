#include <stdio.h>

int main(void) {

	int isLeapYear;

	printf("������ �Է����ּ���. : ");
	scanf("%d", &isLeapYear);

	if (isLeapYear % 4 == 0 || (isLeapYear % 100 == 0 && isLeapYear % 400 == 0)) {
		printf("1");
	}
	else {
		printf("0");
	}
}
	