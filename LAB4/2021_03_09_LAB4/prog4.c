#include <stdio.h>

int main(void) {

	int hour, min, sec, total_sec;

	printf("1. �ð�, ��, �ʸ� �Է����ּ��� : ");
	scanf("%d %d %d", &hour, &min, &sec);

	total_sec = hour * 3600 + min * 60 + sec;

	printf("%d�ð� %d�� %d�ʴ� �� %d���Դϴ�.\n\n", hour, min, sec, total_sec);

	printf("2. �ʸ� �Է����ּ��� : ");
	scanf("%d", &total_sec);

	hour = total_sec / 3600;
	min = (total_sec - hour * 3600) / 60;
	sec = (total_sec - hour * 3600 - min * 60);
	printf("%d�ʴ� %d�ð� %d�� %d���Դϴ�.", total_sec, hour, min, sec);

	return 0;
}