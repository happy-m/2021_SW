#include "FileIo.h"
#include <stdio.h>

void ReadTxt(BOOK* book, int* count, int* Max) {

	FILE* file = NULL;
	int fcnt = 0;
	int fmax = 0;
	file = fopen("book.txt", "r");
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	else {
		fscanf(file, "%d\n", &fmax);
		fscanf(file, "%d\n", &fcnt);

		*count = fmax;
	}
	fclose(file);
}

void WriteTxt(BOOK* book, int* Max, int* count) {

	FILE* file = NULL;
	file = fopen("book.txt", "w");
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}

	fprintf(file, "%d ", *Max);
	fprintf(file, "%d\n", *count);
	for (int i = 0; i < *count; i++) {
		fprintf(file, "%s %s %d\n", book[i].bookSubject, book[i].author, book[i].price);
	}
	fclose(file);
}

void loadBook(BOOK* book, int* count, int* Max){
	FILE* file = NULL;
	int fcnt = 0;
	int fmax = 0;

	file = fopen("book.txt", "a+");
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return -1;
	}
	else {
		fscanf(file, "%d\n", &fmax);
		fscanf(file, "%d\n", &fcnt);

		for (int i = 0; i < *count; i++) {
			fscanf(file, "%s %s %d\n", book[i].bookSubject, book[i].author, &book[i].price);
		}
		*Max = fcnt;
	}
	fclose(file);
}