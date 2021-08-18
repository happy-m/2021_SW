#include <stdio.h>
#include <math.h>

int main(void) {

	const double rate = 0.045;
	double money = 1000000, total;
	int period;

	printf("예치기간(년) : ");
	scanf("%d", &period);
	total = money * pow((1 + rate), period);
	printf("만기 시 총 수령액은 %.2f입니다.", total);

	return 0;
}