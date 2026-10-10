#include <stdio.h>
#define LIMIT 5

int main(void) {
    int a[LIMIT][LIMIT];
	int rows, cols;
    printf("Enter rows and cols (1..5): \n");
    if (scanf("%d%d", &rows, &cols) != 2) {
        printf("Input error\n");
        return 1;
    }
    if (rows < 1 || rows > LIMIT || cols < 1 || cols > LIMIT) {
        printf("Size error\n");
        return 1;
    }
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (scanf("%d", &a[row][col]) != 1) {
                printf("Input error\n");
                return 1;
            }
            if (a[row][col] < -1000 || a[row][col] > 1000) {
                printf("Value error\n");
                return 1;
            }
        }
    }
    long long sum_col;
    long long mini_sum_row;
    #include <limits.h>
    long long min_row_sum = LLONG_MAX;
    int index = 0;
    for (int col = 0; col < cols; col++) {
        sum_col = 0;
        for (int row = 0; row < rows; row++) {
            sum_col += a[row][col];
        }
        printf("Summ col: %lld\n", sum_col);
    }
    for (int row = 0; row < rows; row++) {
        mini_sum_row = 0;
        for (int col = 0; col < cols; col++) {
            mini_sum_row += a[row][col];
        }
        if (mini_sum_row < min_row_sum) {
                min_row_sum = mini_sum_row;
                index = row;
        }
    }
    printf("Minimum index: %d\n", index);
    printf("Mimimum summ row: %lld\n", min_row_sum);
    return 0;
}