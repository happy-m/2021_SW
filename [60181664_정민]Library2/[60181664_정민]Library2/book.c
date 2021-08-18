#include "book.h"
#include "stddef.h"
#include <math.h>

void InsertBook(BOOK* book, int* count) {

	printf("저장할 도서명을 입력해주세요. : ");
	gets(book[*count].bookSubject);
	printf("저장할 책의 저자명을 입력해주세요. : ");
	gets(book[*count].author);
	printf("저장할 책의 가격을 입력해주세요. : ");
	scanf("%d", &book[*count].price);
	getchar();

	printf("=========================저장된 책==========================\n");
	printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d원\n", book[*count].bookSubject, book[*count].author, book[*count].price);
	*count = *count + 1;
}
void SearchAuthor(BOOK* book, int* count) {
	BOOK searchAuthor;
	BOOK* resultAuthor;
	int checkAuthor = 0;

	printf("검색할 저자명을 입력해주세요. : ");
	gets(&searchAuthor.author);

	resultAuthor = (int*)bsearch(&searchAuthor, book, *count, sizeof(*book), (int(*)(const void*, const void*))findByAuthor);

	if (resultAuthor == NULL) {
		printf("검색된 도서가 없습니다\n");
	}
	else {
		printf("%s의 도서명은 %s이며 가격은 %d원입니다. \n", &searchAuthor.author, book[resultAuthor - book].bookSubject, book[resultAuthor - book].price);
		printf("해당 도서를 검색한 이유를 선택해주세요.\n1.저자명 수정\n2.도서 삭제\n3.나가기\n");
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

	printf("검색할 도서명을 입력해주세요. : ");
	gets(&searchBookName.bookSubject);

	resultBookName = (int*)bsearch(&searchBookName, book, *count, sizeof(*book), (int(*)(const void*, const void*))findByBookName);

	if (resultBookName == NULL) {
		printf("검색된 도서가 없습니다\n");
	}
	else {
		printf("%s도서의 저자는 %s이며 가격은 %d원입니다. \n", &searchBookName.bookSubject, book[resultBookName - book].author, book[resultBookName - book].price);
		printf("해당 도서를 검색한 이유를 선택해주세요.\n1.도서명 수정\n2.도서 삭제\n3.나가기\n");
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
	printf("=================== 저자명을 수정합니다. ===================\n");
	printf("새로운 저자명 : ");
	gets(book[abs(book - resultBookAuthor)].author);
	printf("====================== 수정된 책 정보 ======================\n");
	printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d\n", book[abs(book - resultBookAuthor)].bookSubject, book[abs(book - resultBookAuthor)].author, book[abs(book - resultBookAuthor)].price);

}

void ModifyBookName(BOOK* book, int* count, BOOK* resultBookName) {
	printf("=================== 도서명을 수정합니다. ===================\n");
	printf("새로운 도서명 : ");
	gets(book[abs(book - resultBookName)].bookSubject);
	printf("====================== 수정된 책 정보 ======================\n");
	printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d\n", book[abs(book - resultBookName)].bookSubject, book[abs(book - resultBookName)].author, book[abs(book - resultBookName)].price);
}

void DeleteBook(BOOK* book, BOOK* resultBook, int* count) {
	for (int j = (abs(book - resultBook)) - 1; j < *count - 1; j++) {
		memcpy(&book[j], &book[j + 1], sizeof(BOOK));
	}
	*count = *count - 1;
	printf("삭제가 완료되었습니다.\n");
}

void PrintAllBook(BOOK* book, int* count) {
	printf("====================== 도서 전체 정보 ======================\n");
	for (int j = 0; j < *count; j++) {
		printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d\n", book[j].bookSubject, book[j].author, book[j].price);
	}
}

void PrintSortPrice(BOOK* book, int* count) {
	printf("=================== 가격순정렬(내림차순) ===================\n");
	for (int j = 0; j < *count; j++) {
		printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d\n", book[j].bookSubject, book[j].author, book[j].price);
	}
}

BOOK* AllocateContacts(int count)
{
	BOOK* result = NULL;
	result = (BOOK*)malloc(sizeof(BOOK) * count);
	if (result == NULL)
		printf("동적 메모리 할당 실패\n");
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