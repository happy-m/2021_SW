#include <stdio.h>
#include "font.h"

void PrintFont(const FONT* pFont) {
	printf("��Ʈ�̸� : %s, ��Ʈũ�� : %d, ��Ʈ�β� : %d", pFont->faceName, pFont->size, pFont->weight);
}