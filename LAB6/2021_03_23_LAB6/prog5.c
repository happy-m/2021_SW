#include <stdio.h>

void reverse(char *A);

int main(void) {

	char array[100];

	printf("���ڿ��� �Է����ּ���. : ");
	gets(array);

	reverse(array);
	printf("���� ��� : %s", array);

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