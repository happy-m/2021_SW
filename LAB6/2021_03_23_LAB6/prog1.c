#include <stdio.h>

void SumOfArray(const int* arr, int size);
int sum = 0;

int main(void) {

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	SumOfArray(a, 10);
	printf("�迭 a�� ���ҵ��� �� : %d", sum);

	return 0;
}

void SumOfArray(const int* arr, int size) {

	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
}