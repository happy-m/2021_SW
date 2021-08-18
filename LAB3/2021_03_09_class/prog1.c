#include <stdio.h>

int main(void) {
	
	int asciiVal;

	printf("아스키코드 값을 입력해주세요. : ");
	scanf("%d", &asciiVal);
	printf("아스키코드 값에 해당하는 값 : %c", asciiVal, asciiVal);

	return 0;	
}