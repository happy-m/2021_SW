#include <stdio.h>

int main(void) {
	int age;
	const double yearTosec = 3.156e7;
	double ageTosec;

	printf("나이를 입력해주세요. : ");
	scanf("%d", &age);
	ageTosec = age * yearTosec;
	printf("%d 살은 약 %e초입니다.", age, ageTosec);

	return 0;
}