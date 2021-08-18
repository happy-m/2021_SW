#include <stdio.h>

int main(void) {

	double c, f; // c : ¼·¾¾, f : È­¾¾

	printf("¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä : ");
	scanf("%lf", &c);

	f = 9.0 / 5.0 * c + 32.0;

	printf("¼·¾¾ %lfµµ´Â È­¾¾ %lfµµ ÀÔ´Ï´Ù.", c, f);

	return 0;
}