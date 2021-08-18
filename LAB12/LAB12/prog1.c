#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* file1, * file2;

	file1 = fopen(argv[1], "r");
	if (file1 == NULL) {
		printf("%s 파일 열기 실패\n", argv[1]);
		return -1;
	}

	file2 = fopen(argv[2], "r");
	if (file2 == NULL) {
		printf("%s 파일 열기 실패\n", argv[2]);
		return -1;
	}

	while (1) {
		int c1 = fgetc(file1);
		int c2 = fgetc(file2);

		if (c1 == EOF || c2 == EOF) {
			break;
		}
		if (c1 != c2) {

			printf("두 파일은 서로 다릅니다.\n");

			return 0;

		}

	}

	printf("두 파일은 서로 같습니다.\n");

	fclose(file1);
	fclose(file2);

	return 0;

}