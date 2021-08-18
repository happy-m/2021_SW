#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int CompareByName(const void* e1, const void* e2);
int* find(const void* key, const void* base);

typedef struct font {
	char faceName[40];  // 폰트명
	unsigned int size;    // 폰트 크기
	int weight;             // 폰트 두께
} FONT;

int main(void) {

	FONT* result, fontName;
	FONT font[3] = { { "궁서", 11, 10 },
					 { "함초롱바탕",12, 9 },
					 { "바탕", 10, 12 } };

	int size = sizeof(font) / sizeof(font[0]);
	printf("size : %d\n", size);
	printf("sizeof(font) : %d\n", sizeof(font));
	printf("sizeof(font[0]) : %d\n", sizeof(font[0]));
	qsort(font, 3, sizeof(FONT), CompareByName);

	printf("=== 폰트 이름순 출력 ===\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%-16s %d %d\n", font[i].faceName, font[i].size, font[i].weight);
	} 

	printf("검색할 폰트명을 입력해주세요 : ");
	scanf("%s", &fontName.faceName);

	result = (int*)bsearch(&fontName, font, size, sizeof(FONT), (int(*)(const void*, const void*))find);

	if (result == NULL) {
		printf("검색된 폰트가 없습니다\n");
	}
	else {
		printf("%s은(는) font[%d]에 있습니다 \n", fontName.faceName, (int)(result-font));
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