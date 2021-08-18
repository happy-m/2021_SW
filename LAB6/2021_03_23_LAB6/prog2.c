#include <stdio.h>
#include <time.h>
#define MAXSIZE 10

void RnumberGen(int *A, int size, int range);
void GetMinMax(int arr[], int size);

int max;
int min;

int main(void) {
	int arr[MAXSIZE];
	RnumberGen(arr, 10, 100);
	GetMinMax(arr, 10);
	printf("ÃÖ´ñ°ª : %d, ÃÖ¼Ú°ª : %d", max, min);

	return 0;
}

void RnumberGen(int *A, int size, int range) {
	int i;

	srand(time(NULL));
	for (i = 0; i < size; i++) {
		A[i] = rand() % range + 1;

		printf("·£´ý ³­¼ö : %d\n", A[i]);
	}
}

void GetMinMax(int arr[], int size) {
	max = arr[0];
	min = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		} 	
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return max, min;

	
}