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
        printf("==================== ���� ���� ���α׷� ====================\n");
        printf("�޴��� �����ϼ���.\n1.�����Է�\n2.���ں� �˻�\n3.���� �˻�\n4.���ݼ����� ����\n5.��\n");
        printf("============================================================\n");
        scanf("%d", &select);
        while (getchar() != '\n');

        switch (select) {
        case 1:
            if (cnt == BOOKMAX) {
                printf("���̻� ������ �� �����ϴ�.\n");
            }
            else {

                printf("������ �������� �Է����ּ���. : ");
                gets(book[cnt]->bookSubject);
                printf("������ å�� ���ڸ��� �Է����ּ���. : ");
                gets(book[cnt]->author);
                printf("������ å�� ������ �Է����ּ���. : ");
                scanf("%d", &book[cnt]->price);
                getchar();

                cnt = cnt + 1;

            }
            printf("=========================����� å==========================\n");
            for (int i = 0; i < cnt; i++) {
                printf("������ : %-12s, ���ڸ� : %-12s, ���� : %-6d��\n", book[i]->bookSubject, book[i]->author, book[i]->price);
            }
            break;
        case 2:
            printf("�˻��� ���ڸ��� �Է����ּ���. : ");
            gets(writer.author);
            qsort(book, cnt, sizeof(*book), CompareByAuthor);

            result = (int*)bsearch(&writer, book, cnt, sizeof(*book), (int(*)(const void*, const void*))findByAuthor);

            if (result == NULL) {
                printf("�˻��� ������ �����ϴ�\n");
            }
            else {
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(writer.author, book[i]->author) == 0) {
                        found = i;
                        break;
                    }
                }
                printf("%s�� �������� %s�̸� ������ %d���Դϴ�. \n", writer.author, book[found]->bookSubject, book[found]->price);
            }
            break;

        case 3:
            printf("�˻��� �������� �Է����ּ���. : ");
            gets(bookName.bookSubject);
            qsort(book, cnt, sizeof(*book), CompareByName);

            result = (int*)bsearch(&bookName, book, cnt, sizeof(*book), (int(*)(const void*, const void*))findByBookName);

            if (result == NULL) {
                printf("�˻��� ������ �����ϴ�\n");
            }
            else {
                for (int i = 0; i < cnt; i++) {
                    if (strcmp(bookName.bookSubject, book[i]->bookSubject) == 0) {
                        found = i;
                        break;
                    }
                }
                printf("%s������ ���ڴ� %s�̸� ������ %d���Դϴ�. \n", bookName.bookSubject, book[found]->author, book[found]->price);
            }
            break;
        case 4:
            printf("================== ���ݼ� ���� (��������) ==================\n");

            qsort(book, cnt, sizeof(*book), CompareByPrice);
            for (int i = 0; i < cnt; i++) {
                printf("������ : %-12s, ���ڸ� : %-12s, ���� : %-6d\n", book[i]->bookSubject, book[i]->author, book[i]->price);
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
            printf("�ٽ� �������ּ���\n");
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