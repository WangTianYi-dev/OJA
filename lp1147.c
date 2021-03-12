#include <stdio.h>
// #define DEBUG
int n;
int a[1000001];
#ifndef DEBUG
void quickSort(int l, int r)
{
    int mid = a[(l + r) >> 1];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < mid)
            i++;
        while (mid < a[j])
            j--;
        if (i <= j) {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
            i++;
            j--;
        }
    }
    if (l < j)
        quickSort(l, j);
    if (i < r)
        quickSort(i, r);
}
#endif
#ifdef DEBUG
void quickSort(int l, int r) //应用二分思想
{
    int mid = a[(l + r) / 2]; //中间数
    int i = l, j = r - 1;
    printf("i: %d, j: %d\n", i, j);
    do {
        while (a[i] < mid)
            i++; //查找左半部分比中间数大的数
        while (a[j] > mid)
            j--; //查找右半部分比中间数小的数
        if (i <= j) //如果有一组不满足排序条件（左小右大）的数
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    } while (i <= j); //这里注意要有=
    if (l < j)
        quickSort(l, j); //递归搜索左半部分
    if (i < r)
        quickSort(i, r); //递归搜索右半部分
}
#endif
int main()
{
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
