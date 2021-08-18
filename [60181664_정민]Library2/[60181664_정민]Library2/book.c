#include "book.h"
#include "stddef.h"
#include <math.h>

void InsertBook(BOOK* book, int* count) {

	printf("������ �������� �Է����ּ���. : ");
	gets(book[*count].bookSubject);
	printf("������ å�� ���ڸ��� �Է����ּ���. : ");
	gets(book[*count].author);
	printf("������ å�� ������ �Է����ּ���. : ");
	scanf("%d", &book[*count].price);
	getchar();

	printf("=========================����� å==========================\n");
	printf("������ : %-12s, ���ڸ� : %-12s, ���� : %-6d��\n", book[*count].bookSubject, book[*count].author, book[*count].price);
	*count = *count + 1;
}
void SearchAuthor(BOOK* book, int* count) {
	BOOK searchAuthor;
	BOOK* resultAuthor;
	int checkAuthor = 0;

	printf("�˻��� ���ڸ��� �Է����ּ���. : ");
	gets(&searchAuthor.author);

	resultAuthor = (int*)bsearch(&searchAuthor, book, *count, sizeof(*book), (int(*)(const void*, const void*))findByAuthor);

	if (resultAuthor == NULL) {
		printf("�˻��� ������ �����ϴ�\n");
	}
	else {
		printf("%s�� �������� %s�̸� ������ %d���Դϴ�. \n", &searchAuthor.author, book[resultAuthor - book].bookSubject, book[resultAuthor - book].price);
		printf("�ش� ������ �˻��� ������ �������ּ���.\n1.���ڸ� ����\n2.���� ����\n3.������\n");
		scanf("%d", &checkAuthor);
		getchar();

		switch (checkAuthor) {
		case 1:
			ModifyBookAuthor(book, count, resultAuthor);
			break;
		case 2:
			DeleteBook(resultAuthor, book, count);
			break;
		case 3:
			break;
		default:
			break;
		} 
	}
}
void SearchBookName(BOOK* book, int* count) {
	BOOK searchBookName;
	BOOK* resultBookName;
	int checkBook = 0;

	printf("�˻��� �������� �Է����ּ���. : ");
	gets(&searchBookName.bookSubject);

	resultBookName = (int*)bsearch(&searchBookName, book, *count, sizeof(*book), (int(*)(const void*, const void*))findByBookName);

	if (resultBookName == NULL) {
		printf("�˻��� ������ �����ϴ�\n");
	}
	else {
		printf("%s������ ���ڴ� %s�̸� ������ %d���Դϴ�. \n", &searchBookName.bookSubject, book[resultBookName - book].author, book[resultBookName - book].price);
		printf("�ش� ������ �˻��� ������ �������ּ���.\n1.������ ����\n2.���� ����\n3.������\n");
		scanf("%d", &checkBook);
		getchar();

		switch (checkBook) {
		case 1:
			ModifyBookName(book, count, resultBookName);
			break;
		case 2:
			DeleteBook(resultBookName, book, count);
			break;
		case 3:
			break;
		default:
			break;
		}
	}
}

void ModifyBookAuthor(BOOK* book, int* count, BOOK* resultBookAuthor) {
	printf("=================== ���ڸ��� �����մϴ�. ===================\n");
	printf("���ο� ���ڸ� : ");
	gets(book[abs(book - resultBookAuthor)].author);
	printf("====================== ������ å ���� ======================\n");
	printf("������ : %-12s, ���ڸ� : %-12s, ���� : %-6d\n", book[abs(book - resultBookAuthor)].bookSubject, book[abs(book - resultBookAuthor)].author, book[abs(book - resultBookAuthor)].price);

}

void ModifyBookName(BOOK* book, int* count, BOOK* resultBookName) {
	printf("=================== �������� �����մϴ�. ===================\n");
	printf("���ο� ������ : ");
	gets(book[abs(book - resultBookName)].bookSubject);
	printf("====================== ������ å ���� ======================\n");
	printf("������ : %-12s, ���ڸ� : %-12s, ���� : %-6d\n", book[abs(book - resultBookName)].bookSubject, book[abs(book - resultBookName)].author, book[abs(book - resultBookName)].price);
}

void DeleteBook(BOOK* book, BOOK* resultBook, int* count) {
	for (int j = (abs(book - resultBook)) - 1; j < *count - 1; j++) {
		memcpy(&book[j], &book[j + 1], sizeof(BOOK));
	}
	*count = *count - 1;
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
}

void PrintAllBook(BOOK* book, int* count) {
	printf("====================== ���� ��ü ���� ======================\n");
	for (int j = 0; j < *count; j++) {
		printf("������ : %-12s, ���ڸ� : %-12s, ���� : %-6d\n", book[j].bookSubject, book[j].author, book[j].price);
	}
}

void PrintSortPrice(BOOK* book, int* count) {
	printf("=================== ���ݼ�����(��������) ===================\n");
	for (int j = 0; j < *count; j++) {
		printf("������ : %-12s, ���ڸ� : %-12s, ���� : %-6d\n", book[j].bookSubject, book[j].author, book[j].price);
	}
}

BOOK* AllocateContacts(int count)
{
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * count);
	if (result == NULL)
		printf("���� �޸� �Ҵ� ����\n");
	else
		memset(result, 0, sizeof(BOOK) * count);
	return result;
}

int* findByAuthor(const void* writer1, const void* writer2) {
	const BOOK* p1 = (const BOOK*)writer1;
	const BOOK* p2 = (const BOOK*)writer2;

	return strcmp(p1->author, p2->author);
}

int* findByBookName(const void* name1, const void* name2) {
	const BOOK* p1 = (const BOOK*)name1;
	const BOOK* p2 = (const BOOK*)name2;

	return strcmp(p1->bookSubject, p2->bookSubject);
}