#include <stdio.h>

void reverse(char *A);

int main(void) {

	char array[100];

	printf("문자열을 입력해주세요. : ");
	gets(array);

	reverse(array);
	printf("역순 출력 : %s", array);

	return 0;
}

void reverse(char *A) {
	for (int i = 0; i < strlen(A)/2; i++) {
		char temp = A[i];
		A[i] = A[strlen(A) - i - 1];
		A[strlen(A) - i - 1] = temp;
	}
	return A;
}