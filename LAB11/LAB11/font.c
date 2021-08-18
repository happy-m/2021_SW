#include <stdio.h>
#include "font.h"

void PrintFont(const FONT* pFont) {
	printf("폰트이름 : %s, 폰트크기 : %d, 폰트두께 : %d", pFont->faceName, pFont->size, pFont->weight);
}