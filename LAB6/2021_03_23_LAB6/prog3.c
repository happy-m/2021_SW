#include <stdio.h>

void MakeLower(char *p);
void MakeUpper(char *p);

int main(void) {
	char str[100];

	while (1) {

		printf("���ڿ��� �Է����ּ��� : ");
		gets(str);
		int size = strlen(str);

		if (size - 1 == -1) {
			break;
		}
		else if (size - 1 != -1) {
			MakeLower(str);
			printf("���ڿ� �ҹ��� ��ȯ : %s ", str);
			MakeUpper(str);
			printf("���ڿ� �빮�� ��ȯ : %s\n", str);
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