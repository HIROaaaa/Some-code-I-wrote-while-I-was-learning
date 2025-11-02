#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int arr[10];
    int sum_even = 0;
    int sum_odd = 0;

    double avg_even, avg_odd;

    printf("请输入10个整数：");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            sum_even += arr[i];
        }
        else {
            sum_odd += arr[i];
        }
    }

    avg_even = (double)sum_even / 5;
    avg_odd = (double)sum_odd / 5;

    printf("下标为0、2、4、6、8的元素平均值：%.2f\n", avg_even);
    printf("下标为1、3、5、7、9的元素平均值：%.2f\n", avg_odd);

    return 0;
}

