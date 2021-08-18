#include <stdio.h>

void isAcscending(int* arr, int left, int right);

int main(void) {
	int n, select;
	int arr[10] = { 1, 3, 98, 44, 67, 82, 24, 50, 31, 75 };
	n = sizeof(arr);

	printf("quickSort 방식을 선택해주세요\n");
	print("1. 오름차순\n 2.내림차순\n");
	scanf("%d", &select);

	if (select == 1) {
		isAcscending(arr, 0, n);
	} else if (select == 2) { 
		
	}

	return 0;
}

void isAcscending(int* arr, int left, int right) {
	left = 0;
	right = sizeof(arr);
	int n = sizeof(arr);
	int pivot = arr[0];
	int temp;

	while (1) {
		while (arr[++left] > pivot);
		while (arr[right--] < pivot);

		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;

		if (left >= right) {
			break;
		}
	}
	isAcscending(arr, left, pivot - 1);
	isAcscending(arr, pivot + 1, right);

}