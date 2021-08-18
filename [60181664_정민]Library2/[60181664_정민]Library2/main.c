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
		printf("최대 저장가능한 도서의 개수를 입력해주세요. : ");
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
		printf("==================== 도서 관리 프로그램 ====================\n");
		printf("메뉴를 선택하세요.\n1.도서입력\n2.저자별 검색\n3.제목 검색\n4.가격순으로 정렬\n5.도서 전체 정보\n6.끝\n");
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
