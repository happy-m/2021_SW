#include <stdio.h>

int main(void) {

	double total, money = 1000000;
	const double rate = 0.045;
	int period;

	printf("예치기간(년) : ");
	scanf("%d", &period);
	total = money * (1 + rate * period);
	printf("만기 시 총 수령액 : %.2f", total);

	return 0;
}