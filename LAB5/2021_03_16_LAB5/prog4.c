#include <stdio.h>

int main(void) {

	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		if (i % 7 == 0) {
			continue;
		}
		sum += i;
	}
	printf("7�� ����� �ƴ� ���ڵ��� �� : %d", sum);
	return 0;
}
