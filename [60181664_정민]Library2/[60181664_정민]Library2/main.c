#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileIo.h"

int main(int argc, char* argv[]) {
	int max = 0;
	int select = 0;
	int cnt = 0;
	int* count = &cnt;
	int flag = 0;
	BOOK* book = NULL;
	int* Max = &max;

	ReadTxt(book, count, Max);
	int reall = *count;
	if (*count == 0) {
		printf("�ִ� ���尡���� ������ ������ �Է����ּ���. : ");
		scanf("%d", &max);
		getchar();
		book = AllocateContacts(max);
		Max = &max;
	}
	else {
		book = AllocateContacts(reall);
		loadBook(book, count, Max);
		cnt = *Max;
		Max = &reall; 
		count = &cnt;
	}
	while (1) {
		printf("==================== ���� ���� ���α׷� ====================\n");
		printf("�޴��� �����ϼ���.\n1.�����Է�\n2.���ں� �˻�\n3.���� �˻�\n4.���ݼ����� ����\n5.���� ��ü ����\n6.��\n");
		printf("============================================================\n");
		scanf("%d", &select);
		getchar();

		if (select == 6) {
			WriteTxt(book, Max, count);

			free(book);
			book = NULL;
			break;
		}
		SelectMenu(select, cnt, Max, book, count);
	}
	return 0;
}
