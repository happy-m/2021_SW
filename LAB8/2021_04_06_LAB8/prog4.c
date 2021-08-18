#include <stdio.h>

//void isAcsending(int* arr, int n);
// void isDeAcsceding(int* arr, int n);

int main(void) {
	int n, i, select;
	int arr[10];

	printf("정렬할 숫자 10개를 입력해주세요");
	scanf("%d", &n);

	printf("quickSort 방식을 선택해주세요\n");
	print("1. 오름차순\n 2.내림차순\n");
	scanf("%d", &select);

	while (1) {
		if (select == 1) {
			isAcsending(arr, 0, n-1);
			for (int i = 0; i < sizeof(arr); i++) {
				printf("오름차순 정렬 : %d", arr[i]);
			}
		}
		else if (select == 2) {
		//	isDeAcsceding(arr, n);
		}
	}
	return 0;

}

//void isAcsending(int* arr, int left, int right) {

//}
