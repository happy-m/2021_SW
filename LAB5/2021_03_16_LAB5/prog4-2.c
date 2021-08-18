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

	printf("7의 배수가 아닌 숫자들의 합 : %d", sum);
	return 0;
}
