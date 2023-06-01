//
// Created by LHQvQ on 2023/6/1.
//

#ifndef ALGORITHM_TEMPLATE_BINARY_SEARCH_H
#define ALGORITHM_TEMPLATE_BINARY_SEARCH_H

/* 二分查找，查找第一个和最后一个匹配元素的下标 ------------------------ logn
const int N = 100010;
int a[N];
int n, q;
void binary_search(int a[]) {

    int k;
    scanf("%d", &k);

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= k) r = mid;
        else l = mid + 1;
    }

    if (a[l] != k) printf("%d %d\n", -1, -1);
    else {
        printf("%d ", l);

        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= k) l = mid;
            else r = mid - 1;
        }

        printf("%d\n", l);
    }
}
*/

/* 浮点二分，数的三次方根 ---------------------------------
void binary_search(double x) {
    double l = -100, r = 100;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid > x) r = mid;
        else l = mid;
    }

    printf ("%.6lf", l);
}
 */

#endif //ALGORITHM_TEMPLATE_BINARY_SEARCH_H
