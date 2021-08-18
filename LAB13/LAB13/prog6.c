#include <stdio.h>

int fibo(int num);

int main(void) {
	int num;

	printf("�������� �Է����ּ��� (10~30) : ");
	scanf("%d", &num);

	for (int i = 0; i <= num; i++) {
		fibo(i);
	}
	printf("���� %d�� �ش��ϴ� �Ǻ���ġ�� %d�Դϴ�.", num, fibo(num));

	return 0;
}

int fibo(int num) {
	if (num == 0) {
		return 0;
	}
	else if (num == 1) {
		return 1;
	}
	else if (num >= 2) {
		return fibo(num - 2) + fibo(num - 1);
	}
}