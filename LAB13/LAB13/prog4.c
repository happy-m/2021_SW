#include <stdio.h>

typedef struct movePoint2D {
	int x;
	int y;
	int moveX;
	int moveY;
}Move;

int main(void) {
	Move dot, move;

	printf("x, y��ǥ�� �Է����ּ��� : ");
	scanf("%d %d", &dot.x, &dot.y);
	getchar();
	printf("�̵��� x, y��ǥ�� �Է����ּ��� : ");
	scanf("%d %d", &move.x, &move.y);
	getchar();

	int mX = dot.x + move.x;
	int mY = dot.y + move.y;

	printf("�̵��� ���� ��ǥ�� (%d, %d)�Դϴ�.", mX, mY);

	return 0;
}