#include <stdio.h>
#include <limits.h>

int main(void) {

	printf("int ÃÖ´ñ°ª : %d, ÃÖ´ñ°ª+1 : %d, ÃÖ¼Ú°ª : %d, ÃÖ¼Ú°ª-1 : %d \n", INT_MAX, INT_MAX+1, INT_MIN, INT_MIN-1);
	printf("unsigned int ÃÖ´ñ°ª : %u, ÃÖ´ñ°ª+1 : %u, ÃÖ¼Ú°ª : %u, ÃÖ¼Ú°ª-1 : %u \n", UINT_MAX, UINT_MAX+1, 0, -1);

	return 0;
}