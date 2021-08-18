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
	printf("7의 배수가 아닌 숫자들의 합 : %d", sum);
	return 0;
}
