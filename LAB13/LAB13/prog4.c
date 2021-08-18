#include <stdio.h>

typedef struct movePoint2D {
	int x;
	int y;
	int moveX;
	int moveY;
}Move;

int main(void) {
	Move dot, move;

	printf("x, y좌표를 입력해주세요 : ");
	scanf("%d %d", &dot.x, &dot.y);
	getchar();
	printf("이동할 x, y좌표를 입력해주세요 : ");
	scanf("%d %d", &move.x, &move.y);
	getchar();

	int mX = dot.x + move.x;
	int mY = dot.y + move.y;

	printf("이동한 점의 좌표는 (%d, %d)입니다.", mX, mY);

	return 0;
}