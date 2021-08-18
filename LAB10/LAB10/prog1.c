#include <stdio.h>

void SumOfArray(int* pA, int* pB);

int main(void) {
    int arrA[3][10] = { {1,2,3,4,5,6,7,8,9,10}, {11,12,13,14,15,16,17,18,19,20}, {21,22,23,24,25,26,27,28,29,30} };

    int arrB[3];
    SumOfArray(arrA, arrB);


    return 0;
}
void SumOfArray(int(*pA)[10], int* pB) {
    int i;
    int sum = 0;
    for (i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            sum = pA[i][j] + sum;
            pB[i] = sum;
        }
        printf("ºÎºÐÇÕ : %d\n", pB[i]);
        sum = 0;

    }
}