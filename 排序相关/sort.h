//
// Created by LHQvQ on 2023/6/1.
//

#ifndef ALGORITHM_TEMPLATE_SORT_H
#define ALGORITHM_TEMPLATE_SORT_H

/* 快速排序 -------------------------------------- nlogn。m
const int N = 100010;

int a[N];
int n;

void quickSort(int a[], int l, int r) {
    if (l >= r) return;

    int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    quickSort(a, l, j);
    quickSort(a, j + 1, r);
}
*/

/* 快速排序。排序前 k 个数 -------------------------------------- nlogn。m
const int N = 100010;

int a[N];
int n, k;

void quickSort_k(int a[], int l, int r) {
    if (l >= r) return;

    int x = a[(l + r) >> 1];
    int i = l - 1, j = r + 1;

    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    quickSort(a, l, j);
    quickSort(a, j + 1, r);
}
 */


/* 归并排序 -------------------------------------- nlogn，nolgn
const int N = 100010;

int a[N], temp[N];
int n;

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid)  temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int i = l, j = 0; i <= r; i++, j++) a[i] = temp[j];
}
*/

/* 归并排序，求逆序对数量 -------------------------------------- nlogn，nolgn
typedef long long LL;

const int N = 100010;

int a[N], temp[N];
int n;

LL mergeSort(int a[], int l, int r) {
    if (l >= r) return 0;

    int mid = l + r >> 1;
    LL res = mergeSort(a, l, mid) + mergeSort(a, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            res += mid - i + 1;
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int i = l, j = 0; i <= r; i++, j++) a[i] = temp[j];

    return res;
}
*/



#endif //ALGORITHM_TEMPLATE_SORT_H
