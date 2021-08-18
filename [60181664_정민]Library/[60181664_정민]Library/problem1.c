#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOKMAX 10
#define MAX 100

typedef struct book {
    char bookSubject[MAX];
    char author[MAX];
    int price;
} BOOK;

int CompareByName(const void* name1, const void* name2);
int CompareByAuthor(const void* writer1, const void* writer2);
int CompareByPrice(const void* price1, const void* price2);
int* findByAuthor(const void* key, const void* base);
int* findByBookName(const void* key, const void* base);

int main(void) {
    int select = 0;
    BOOK* book[BOOKMAX] = { NULL };
    BOOK* result, bookName, writer;
    int i = 0;
    int size = 0;
    int cnt = 0;
    int flag = 0;
    int found = -1;

    for (int i = 0; i < BOOKMAX; i++) {
        book[i] = (BOOK*)malloc(sizeof(BOOK));
        memset(book[i], 0, sizeof(BOOK));
    }
    while (1) {
        printf("==================== 도서 관리 프로그램 ====================\n");
        printf("메뉴를 선택하세요.\n1.도서입력\n2.저자별 검색\n3.제목 검색\n4.가격순으로 정렬\n5.끝\n");
        printf("============================================================\n");
        scanf("%d", &select);
        while (getchar() != '\n');

        switch (select) {
        case 1:
            if (cnt == BOOKMAX) {
                printf("더이상 저장할 수 없습니다.\n");
            }
            else {

                printf("저장할 도서명을 입력해주세요. : ");
                gets(book[cnt]->bookSubject);
                printf("저장할 책의 저자명을 입력해주세요. : ");
                gets(book[cnt]->author);
                printf("저장할 책의 가격을 입력해주세요. : ");
                scanf("%d", &book[cnt]->price);
                getchar();

                cnt = cnt + 1;

            }
            printf("=========================저장된 책==========================\n");
            for (int i = 0; i < cnt; i++) {
                printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d원\n", book[i]->bookSubject, book[i]->author, book[i]->price);
            }
            break;
        case 2:
            printf("검색할 저자명을 입력해주세요. : ");
            gets(writer.author);
            qsort(book, cnt, sizeof(*book), CompareByAuthor);

            result = (int*)bsearch(&writer, book, cnt, sizeof(*book), (int(*)(const void*, const void*))findByAuthor);

            if (result == NULL) {
                printf("검색된 도서가 없습니다\n");
            }
            else {
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(writer.author, book[i]->author) == 0) {
                        found = i;
                        break;
                    }
                }
                printf("%s의 도서명은 %s이며 가격은 %d원입니다. \n", writer.author, book[found]->bookSubject, book[found]->price);
            }
            break;

        case 3:
            printf("검색할 도서명을 입력해주세요. : ");
            gets(bookName.bookSubject);
            qsort(book, cnt, sizeof(*book), CompareByName);

            result = (int*)bsearch(&bookName, book, cnt, sizeof(*book), (int(*)(const void*, const void*))findByBookName);

            if (result == NULL) {
                printf("검색된 도서가 없습니다\n");
            }
            else {
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookName.bookSubject, book[i]->bookSubject) == 0) {
                        found = i;
                        break;
                    }
                }
                printf("%s도서의 저자는 %s이며 가격은 %d원입니다. \n", bookName.bookSubject, book[found]->author, book[found]->price);
            }
            break;
        case 4:
            printf("================== 가격순 정렬 (내림차순) ==================\n");

            qsort(book, cnt, sizeof(*book), CompareByPrice);
            for (int i = 0; i < cnt; i++) {
                printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d\n", book[i]->bookSubject, book[i]->author, book[i]->price);
            }
            break;
        case 5:
            flag = 1;
            for (i = 0; i < cnt; i++) {
                free(book[i]);
                book[i] = NULL;
            }
            break;
        default:
            printf("다시 선택해주세요\n");
            break;
        }
        if (flag == 1) {
            break;
        }

    }
    return 0;
}

int* findByAuthor(const void* writer1, const void* writer2) {
    const BOOK* p1 = (const BOOK*)writer1;
    const BOOK* const* p2 = (const BOOK*)writer2;

    return strcmp(p1->author, (*p2)->author);
}

int* findByBookName(const void* name1, const void* name2) {
    const BOOK* p1 = (const BOOK*)name1;
    const BOOK* const* p2 = (const BOOK*)name2;

    return strcmp(p1->bookSubject, (*p2)->bookSubject);
}

int CompareByPrice(const void* price1, const void* price2) {
    const BOOK* const* f1 = (const BOOK*)price1;
    const BOOK* const* f2 = (const BOOK*)price2;

    if ((*f1)->price < (*f2)->price) {
        return 1;
    }
    else if ((*f1)->price > (*f2)->price) {
        return -1;
    }
    else if ((*f1)->price == (*f2)->price) {
        return 0;
    }
}

int CompareByName(const void* name1, const void* name2) {
    const BOOK* const* f1 = (const BOOK*)name1;
    const BOOK* const* f2 = (const BOOK*)name2;

    return strcmp((*f1)->bookSubject, (*f2)->bookSubject);
}

int CompareByAuthor(const void* writer1, const void* writer2) {
    const BOOK* const* f1 = (const BOOK*)writer1;
    const BOOK* const* f2 = (const BOOK*)writer2;

    return strcmp((*f1)->author, (*f2)->author);
}