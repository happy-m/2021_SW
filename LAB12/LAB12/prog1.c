#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* file1, * file2;

	file1 = fopen(argv[1], "r");
	if (file1 == NULL) {
		printf("%s ���� ���� ����\n", argv[1]);
		return -1;
	}

	file2 = fopen(argv[2], "r");
	if (file2 == NULL) {
		printf("%s ���� ���� ����\n", argv[2]);
		return -1;
	}

	while (1) {
		int c1 = fgetc(file1);
		int c2 = fgetc(file2);

		if (c1 == EOF || c2 == EOF) {
			break;
		}
		if (c1 != c2) {

			printf("�� ������ ���� �ٸ��ϴ�.\n");

			return 0;

		}

	}

	printf("�� ������ ���� �����ϴ�.\n");

	fclose(file1);
	fclose(file2);

	return 0;

}