#include <stdio.h>

int main(void) {

	double total, money = 1000000;
	const double rate = 0.045;
	int period;

	printf("��ġ�Ⱓ(��) : ");
	scanf("%d", &period);
	total = money * (1 + rate * period);
	printf("���� �� �� ���ɾ� : %.2f", total);

	return 0;
}