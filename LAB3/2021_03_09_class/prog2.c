#include <stdio.h>

int main(void) {

	char ch;

	printf("문자를 입력해주세요. : ");
	scanf("%c", &ch);
	printf("문자에 해당하는 아스키코드 값 : %d", ch, ch);

	return 0;
}