#include <stdio.h>

int main(void) {
	
	char ch;

	printf("���ڸ� �Է����ּ���. : ");
	scanf("%c", &ch);

	for (int i = 0; i < 7; i++) {
		for (int j = 6; j > i; j--) {
			printf(" ");
		}
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("%c", ch);
		}
		printf("\n");
	}
	return 0;
}