#include <stdio.h>

int main(void) {

	int sum = 0;
	int i = 0;

	do {
		i++;
		if (i % 7 == 0) {
			continue;
		}
		sum += i;
	} while (i < 100); 

	printf("7�� ����� �ƴ� ���ڵ��� �� : %d", sum);
	return 0;
}
