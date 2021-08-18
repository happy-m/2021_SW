#include <stdio.h>

int main(void) {

	int isLeapYear;

	printf("연도를 입력해주세요. : ");
	scanf("%d", &isLeapYear);

	if (isLeapYear % 4 == 0 || (isLeapYear % 100 == 0 && isLeapYear % 400 == 0)) {
		printf("1");
	}
	else {
		printf("0");
	}
}
	