#include <stdio.h>

//void isAcsending(int* arr, int n);
// void isDeAcsceding(int* arr, int n);

int main(void) {
	int n, i, select;
	int arr[10];

	printf("������ ���� 10���� �Է����ּ���");
	scanf("%d", &n);

	printf("quickSort ����� �������ּ���\n");
	print("1. ��������\n 2.��������\n");
	scanf("%d", &select);

	while (1) {
		if (select == 1) {
			isAcsending(arr, 0, n-1);
			for (int i = 0; i < sizeof(arr); i++) {
				printf("�������� ���� : %d", arr[i]);
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
