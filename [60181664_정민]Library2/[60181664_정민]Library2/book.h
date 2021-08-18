#define MAX 100

typedef struct book {
	char bookSubject[MAX];
	char author[MAX];
	int price;
} BOOK;

BOOK* AllocateContacts(int max);

void PrintSortPrice(BOOK* book, int* count);
void InsertBook(BOOK* book, int* count);
void SearchAuthor(BOOK* book, int* count);
void SearchBookName(BOOK* book, int* count);
void PrintAllBook(BOOK* book, int* count);

int* findByAuthor(const void* key, const void* base);
int* findByBookName(const void* key, const void* base);

void DeleteBook(BOOK* book, BOOK* resultBook, int* count);
void ModifyBookName(BOOK* book, int* count, BOOK* resultBookName);
void ModifyBookAuthor(BOOK* book, int* count, BOOK* resultBookName);