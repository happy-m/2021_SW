#include "menu.h"
#include "stddef.h" 

int CompareByPrice(const void* price1, const void* price2) {
	const BOOK* f1 = (const BOOK*)price1;
	const BOOK* f2 = (const BOOK*)price2;

	if (f1->price < f2->price) {
		return 1;
	}
	else if (f1->price > f2->price) {
		return -1;
	}
	else if (f1->price == f2->price) {
		return 0;
	}
}

int CompareByName(const void* name1, const void* name2) {
	const BOOK* f1 = (const BOOK*)name1;
	const BOOK* f2 = (const BOOK*)name2;

	return strcmp(f1->bookSubject, f2->bookSubject);
}

int CompareByAuthor(const void* writer1, const void* writer2) {
	const BOOK* f1 = (const BOOK*)writer1;
	const BOOK* f2 = (const BOOK*)writer2;

	return strcmp(f1->author, f2->author);
}

void SelectMenu(int select, int cnt, int* Max, BOOK* book, int* count) {
	int select2 = 0;

	switch (select) {
	case 1:
		if (cnt == *Max) {
			printf("���̻� ������ �� �����ϴ�.\n");
			printf("������ �� �����Ͻðڽ��ϱ�?\n1.����\n2.������\n");
			scanf("%d", &select);
			getchar();

			switch (select) {
			case 1:
				printf("�� ����ŭ ���� ũ�⸦ �ø��ðڽ��ϱ�?\n");
				scanf("%d", &select2);
				*Max += select2;
				book = (BOOK*)realloc(book, (sizeof(BOOK) * (*Max)));
				if (book == NULL) {
					printf("���� �޸� �Ҵ� ����\n");
				}
				else {
					printf("%d��ŭ ��������� �÷Ƚ��ϴ�.\n", select2);
				}
				break;
			case 2:
				printf("���� ������ �ø��� �ʽ��ϴ�.\n");
				break;
			default:
				printf("���� ������ �ø��� �ʽ��ϴ�.\n");
				break;
			}
		}
		else {
			InsertBook(book, count);
		}
		break;
	case 2:
		qsort(book, cnt, sizeof(*book), CompareByAuthor);
		SearchAuthor(book, count);
		break;

	case 3:
		qsort(book, cnt, sizeof(*book), CompareByName);
		SearchBookName(book, count);
		break;
	case 4:
		qsort(book, cnt, sizeof(*book), CompareByPrice);
		PrintSortPrice(book, count);
		break;
	case 5:
		PrintAllBook(book, count);
		break;
	default:
		printf("�ٽ� �������ּ���\n");
		break;
	}
}