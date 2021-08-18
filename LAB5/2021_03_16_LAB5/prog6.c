#include <stdio.h>

void plusValue(int value);
void minusValue(int value);
int g_result = 0;

int main(void) {

	int value;
	char oper;

	while (1) {
		printf("원하는 연산(+ 혹은 -)을 입력해주세요. : ");
		scanf("%c", &oper);
		if (oper == '0') {
			printf("%d", g_result);
			break;
		}

		printf("원하는 정수값을 입력해주세요. : ");
		scanf("%d", &value);
		getchar();

		if (oper == '+') {
			plusValue(value);
		}
		else if (oper == '-') {
			minusValue(value);
		}
	}

	return 0;
}

void plusValue(int value) {
	g_result += value;
}

void minusValue(int value) {
	g_result -= value;
}
