#include <stdio.h>

int main(void) {

	int hour, min, sec, total_sec;

	printf("1. 시간, 분, 초를 입력해주세요 : ");
	scanf("%d %d %d", &hour, &min, &sec);

	total_sec = hour * 3600 + min * 60 + sec;

	printf("%d시간 %d분 %d초는 총 %d초입니다.\n\n", hour, min, sec, total_sec);

	printf("2. 초를 입력해주세요 : ");
	scanf("%d", &total_sec);

	hour = total_sec / 3600;
	min = (total_sec - hour * 3600) / 60;
	sec = (total_sec - hour * 3600 - min * 60);
	printf("%d초는 %d시간 %d분 %d초입니다.", total_sec, hour, min, sec);

	return 0;
}