#include <stdio.h>

int main(void) {

	int sum = 0;
	int i = 0;	

	while(i < 100) {
		i++;
		if (i % 7 == 0) {
			continue;
		}
			sum += i;	
	}
	printf("7�� ����� �ƴ� ���ڵ��� �� : %d", sum);
	return 0;
}
