#include <stdio.h>

int main(void) {

	double c, f; // c : ����, f : ȭ��

	printf("���� �µ��� �Է����ּ��� : ");
	scanf("%lf", &c);

	f = 9.0 / 5.0 * c + 32.0;

	printf("���� %lf���� ȭ�� %lf�� �Դϴ�.", c, f);

	return 0;
}