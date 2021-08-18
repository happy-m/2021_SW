#include <stdio.h>

void MakeLower(char *p);
void MakeUpper(char *p);

int main(void) {
	char str[100];

	while (1) {

		printf("문자열을 입력해주세요 : ");
		gets(str);
		int size = strlen(str);

		if (size - 1 == -1) {
			break;
		}
		else if (size - 1 != -1) {
			MakeLower(str);
			printf("문자열 소문자 변환 : %s ", str);
			MakeUpper(str);
			printf("문자열 대문자 변환 : %s\n", str);
		}
		
	}
	return 0;
}

void MakeLower(char *p) {
	int i;
	for (i = 0; i < 100; i++) {
		if (p[i] >= 'A' && p[i] <= 'Z') {
			p[i] += 32;
		}
	}
}

void MakeUpper(char *p) {
	int i;
	for (i = 0; i < 100; i++) {
		if (p[i] >= 'a' && p[i] <= 'z') {
			p[i] -= 32;
		}
	}
}