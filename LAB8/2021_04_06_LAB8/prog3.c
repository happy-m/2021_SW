#include <stdio.h>

enum week { sun, mon, tue, wed, thu, fri, sat, Count };

int main(void) {
	
	enum week weekday;

	for (weekday = sun; weekday < Count; weekday++) {
		if (weekday == sun) {
			printf("일요일입니다.\n");
		}
		else if (weekday == mon) {
			printf("월요일입니다.\n");
		}
		else if (weekday == tue) {
			printf("화요일입니다.\n");
		}
		else if (weekday == wed) {
			printf("수요일입니다.\n");
		}
		else if (weekday == thu) {
			printf("목요일입니다.\n");
		}
		else if (weekday == fri) {
			printf("금요일입니다.\n");
		}
		else {
			printf("토요일입니다.\n");

		}
	}

	return 0;
}