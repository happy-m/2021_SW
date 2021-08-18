#include <stdio.h>
#include <math.h>

struct point2D {
	int x[4];
	int y[4];
};

int main(void) {
	struct point2D dot[4] = { NULL };
	int i = 0;
	double distance = 0;

	printf("좌표를 입력해주세요\n");
	for (i = 0; i < 4; i++) {
		scanf("%d %d", &dot[i].x, &dot[i].y);
		getchar();
	}

	for (int j = 0; j < 3; j++) {
		int a = dot[j + 1].x - dot[j].x;
		int b = dot[j + 1].y - dot[j].y;

		distance += sqrt((a * a) + (b * b));
	}
	printf("선의 총 길이 : %f", distance);

}

