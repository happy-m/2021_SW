#include <stdio.h>

int main(void) {
	int age;
	const double yearTosec = 3.156e7;
	double ageTosec;

	printf("���̸� �Է����ּ���. : ");
	scanf("%d", &age);
	ageTosec = age * yearTosec;
	printf("%d ���� �� %e���Դϴ�.", age, ageTosec);

	return 0;
}