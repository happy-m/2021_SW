#include <stdio.h>
#include <math.h>

int main(void) {

	const double rate = 0.045;
	double money = 1000000, total;
	int period;

	printf("��ġ�Ⱓ(��) : ");
	scanf("%d", &period);
	total = money * pow((1 + rate), period);
	printf("���� �� �� ���ɾ��� %.2f�Դϴ�.", total);

	return 0;
}