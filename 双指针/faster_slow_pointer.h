//
// Created by LHQvQ on 2023/6/1.
//

#ifndef ALGORITHM_TEMPLATE_FASTER_SLOW_POINTER_H
#define ALGORITHM_TEMPLATE_FASTER_SLOW_POINTER_H

/* 最长连续不重复子序列 ----------------------------------------- n
#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;

int s[N];

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        s[a[i]]++;
        while (s[a[i]] > 1) {
            s[a[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }

    printf("%d", res);

    return 0;
}
*/

/* 数组元素的目标和，A[i] + B[j] = x --------------------------------------------- n
#include <iostream>
using namespace std;

const int N = 100010;

int a[N], b[N];
int n, m, x;

int main() {

    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (j >= 0 && a[i] + b[j] == x) printf("%d %d", i, j);
    }

    return 0;
}
*/

/* 判断 a 是否为 b 的子序列 ------------------------------------------ n
#include <iostream>
using namespace std;

const int N = 100010;

int a[N], b[N];
int n, m;

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) i++;
        j++;
    }

    if (i == n) printf("Yes");
    else printf("No");

    return 0;
}
*/

#endif //ALGORITHM_TEMPLATE_FASTER_SLOW_POINTER_H
