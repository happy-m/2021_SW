#include <stdio.h>

enum week { sun, mon, tue, wed, thu, fri, sat, Count };

int main(void) {
	
	enum week weekday;

	for (weekday = sun; weekday < Count; weekday++) {
		if (weekday == sun) {
			printf("�Ͽ����Դϴ�.\n");
		}
		else if (weekday == mon) {
			printf("�������Դϴ�.\n");
		}
		else if (weekday == tue) {
			printf("ȭ�����Դϴ�.\n");
		}
		else if (weekday == wed) {
			printf("�������Դϴ�.\n");
		}
		else if (weekday == thu) {
			printf("������Դϴ�.\n");
		}
		else if (weekday == fri) {
			printf("�ݿ����Դϴ�.\n");
		}
		else {
			printf("������Դϴ�.\n");

		}
	}

	return 0;
}