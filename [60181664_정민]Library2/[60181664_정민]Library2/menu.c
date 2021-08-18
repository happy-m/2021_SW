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
			printf("더이상 저장할 수 없습니다.\n");
			printf("도서를 더 저장하시겠습니까?\n1.저장\n2.나가기\n");
			scanf("%d", &select);
			getchar();

			switch (select) {
			case 1:
				printf("몇 개만큼 저장 크기를 늘리시겠습니까?\n");
				scanf("%d", &select2);
				*Max += select2;
				book = (BOOK*)realloc(book, (sizeof(BOOK) * (*Max)));
				if (book == NULL) {
					printf("동적 메모리 할당 실패\n");
				}
				else {
					printf("%d만큼 저장공간을 늘렸습니다.\n", select2);
				}
				break;
			case 2:
				printf("저장 공간을 늘리지 않습니다.\n");
				break;
			default:
				printf("저장 공간을 늘리지 않습니다.\n");
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
		printf("다시 선택해주세요\n");
		break;
	}
}