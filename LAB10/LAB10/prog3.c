#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int CompareByName(const void* e1, const void* e2);
int* find(const void* key, const void* base);

typedef struct font {
	char faceName[40];  // ��Ʈ��
	unsigned int size;    // ��Ʈ ũ��
	int weight;             // ��Ʈ �β�
} FONT;

int main(void) {

	FONT* result, fontName;
	FONT font[3] = { { "�ü�", 11, 10 },
					 { "���ʷչ���",12, 9 },
					 { "����", 10, 12 } };

	int size = sizeof(font) / sizeof(font[0]);
	printf("size : %d\n", size);
	printf("sizeof(font) : %d\n", sizeof(font));
	printf("sizeof(font[0]) : %d\n", sizeof(font[0]));
	qsort(font, 3, sizeof(FONT), CompareByName);

	printf("=== ��Ʈ �̸��� ��� ===\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%-16s %d %d\n", font[i].faceName, font[i].size, font[i].weight);
	} 

	printf("�˻��� ��Ʈ���� �Է����ּ��� : ");
	scanf("%s", &fontName.faceName);

	result = (int*)bsearch(&fontName, font, size, sizeof(FONT), (int(*)(const void*, const void*))find);

	if (result == NULL) {
		printf("�˻��� ��Ʈ�� �����ϴ�\n");
	}
	else {
		printf("%s��(��) font[%d]�� �ֽ��ϴ� \n", fontName.faceName, (int)(result-font));
	}

	return 0;
}

int CompareByName(const void* e1, const void* e2) {
	const FONT* f1 = (const FONT*) e1;
	const FONT* f2 = (const FONT*) e2;
	return strcmp(f1->faceName, f2->faceName);
}

int* find(const void* s1, const void* s2) {
	const FONT* p1 = (const FONT*)s1;
	const FONT* p2 = (const FONT*)s2;
	return strcmp(p1->faceName, p2->faceName);
}