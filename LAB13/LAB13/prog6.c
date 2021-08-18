#include <stdio.h>

int fibo(int num);

int main(void) {
	int num;

	printf("정수값을 입력해주세요 (10~30) : ");
	scanf("%d", &num);

	for (int i = 0; i <= num; i++) {
		fibo(i);
	}
	printf("정수 %d에 해당하는 피보나치는 %d입니다.", num, fibo(num));

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