#include <stdio.h>

void Encrypt(char *A);

int main(void) {

	char str[100];
	printf("문자열을 입력해주세요 : ");
	gets(str);

	Encrypt(str);

	printf("암호화된 문자열 : %s", str);

	return 0;
}

void Encrypt(char *A) {
	for (int i = 0; i < 100; i++) {
		if (A[i] >= 'A' && A[i] <= 'Z') {
			if (A[i] == 'Z') {
				A[i] = 'A';
			} 
			else {
				A[i] += 1;
			}
		}
		if (A[i] >= 'a' && A[i] <= 'z') {
			if (A[i] == 'z') {
				A[i] = 'a';
			}
			else {
				A[i] += 1;
			}
		}
	}
	return A;
}