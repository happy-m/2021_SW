#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct book {
    char bookSubject[MAX];
    char author[MAX];
    int price;
} BOOK;

BOOK* AllocateContacts(int max);
int CompareByPrice(const void* price1, const void* price2);
int CompareByName(const void* name1, const void* name2);
int CompareByAuthor(const void* writer1, const void* writer2);
int* findByAuthor(const void* key, const void* base);
int* findByBookName(const void* key, const void* base);

int main(void) {
    int select = 0;
    BOOK* book = NULL;
    BOOK* result, bookName, writer;
    int i = 0;
    int max = 0;
    int flag = 0;
    int cnt = 0;


    printf("최대 저장가능한 도서의 개수를 입력해주세요. : ");
    scanf("%d", &max);
    getchar();
    book = AllocateContacts(max);

    while (1) {
        printf("==================== 도서 관리 프로그램 ====================\n");
        printf("메뉴를 선택하세요.\n1.도서입력\n2.저자별 검색\n3.제목 검색\n4.가격순으로 정렬\n5.끝\n");
        printf("============================================================\n");
        scanf("%d", &select);
        while (getchar() != '\n');

        if (select == 5) {
            free(book);
            book = NULL;
            break;
        }

        switch (select) {
        case 1:
            if (cnt == max) {
                printf("더이상 저장할 수 없습니다.\n");
            }
            else {
                printf("저장할 도서명을 입력해주세요. : ");
                gets(book[cnt].bookSubject);
                printf("저장할 책의 저자명을 입력해주세요. : ");
                gets(book[cnt].author);
                printf("저장할 책의 가격을 입력해주세요. : ");
                scanf("%d", &book[cnt].price);
                while (getchar() != '\n');

                cnt = cnt + 1;
            }
            printf("=========================저장된 책==========================\n");
            for (int i = 0; i < cnt; i++) {
                printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d원\n", book[i].bookSubject, book[i].author, book[i].price);
            }
            break;
        case 2:
            printf("검색할 저자명을 입력해주세요. : ");
            gets(writer.author);
            qsort(book, max, sizeof(BOOK), CompareByAuthor);

            result = (int*)bsearch(&writer, book, max, sizeof(BOOK), (int(*)(const void*, const void*))findByAuthor);
            
            if (result == NULL) {
                printf("검색된 도서가 없습니다\n");
            }
            else {
                printf("%s의 도서명은 %s이며 가격은 %d원입니다. \n", writer.author, book[result - book].bookSubject, book[result - book].price);
            }
            break;

        case 3:
            printf("검색할 도서명을 입력해주세요. : ");
            gets(bookName.bookSubject);
            qsort(book, max, sizeof(BOOK), CompareByName);

            result = (int*)bsearch(&bookName, book, max, sizeof(BOOK), (int(*)(const void*, const void*))findByBookName);

            if (result == NULL) {
                printf("검색된 도서가 없습니다\n");
            }
            else {
                printf("%s도서의 저자는 %s이며, 가격은 %d원입니다. \n", bookName.bookSubject, book[result - book].author, book[result - book].price);
            }
            break;

        case 4:
            printf("================== 가격순 정렬 (내림차순) ==================\n");
            qsort(book, max, sizeof(BOOK), CompareByPrice);

            for (int i = 0; i < max; i++) {
                printf("도서명 : %-12s, 저자명 : %-12s, 가격 : %-6d\n", book[i].bookSubject, book[i].author, book[i].price);
            }
            break;
        case 5:
            flag = 1;
            break;
        default:
            printf("다시 입력해주세요.\n");
        }
        if (flag == 1) {
            break;
        }
    }
    return 0;
}

int* findByAuthor(const void* s1, const void* s2) {
    const BOOK* p1 = (const BOOK*)s1;
    const BOOK* p2 = (const BOOK*)s2;
    return strcmp(p1->author, p2->author);
}

int* findByBookName(const void* s1, const void* s2) {
    const BOOK* p1 = (const BOOK*)s1;
    const BOOK* p2 = (const BOOK*)s2;
    return strcmp(p1->bookSubject, p2->bookSubject);
}

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