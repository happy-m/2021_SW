#include <stdio.h>
#include <limits.h>

int main(void) {

	printf("int �ִ� : %d, �ִ�+1 : %d, �ּڰ� : %d, �ּڰ�-1 : %d \n", INT_MAX, INT_MAX+1, INT_MIN, INT_MIN-1);
	printf("unsigned int �ִ� : %u, �ִ�+1 : %u, �ּڰ� : %u, �ּڰ�-1 : %u \n", UINT_MAX, UINT_MAX+1, 0, -1);

	return 0;
}