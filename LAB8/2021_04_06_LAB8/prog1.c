#include <stdio.h>
#include <time.h>

time_t time(time_t* timer);
struct tm* localtime(const time_t* timer);

/*
struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday; // 요일
	int tm_yday; // 1년 중 경과일
	int tm_isdst; // 써머타임
}; */

struct date {
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
} DATE;

int main(void) {

	time_t timer;
	timer = time(NULL);
	time(&timer);
	struct tm* t =localtime(&timer);

	printf("현재날짜시각 : %d년 %d월 %d일 %d시 %d분 %d초\n", t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

	DATE.year = t->tm_year + 1900;
	DATE.month = t->tm_mon + 1;
	DATE.day = t->tm_mday;
	DATE.hour = t->tm_hour;
	DATE.min = t->tm_min;
	DATE.sec = t->tm_sec;

	printf("구조체에 저장된 현재날짜시각 : %d년 %d월 %d일 %d시 %d분 %d초\n", DATE.year, DATE.month, DATE.day, DATE.hour, DATE.min, DATE.sec);
	
	return 0;
}