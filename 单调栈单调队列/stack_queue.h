//
// Created by LHQvQ on 2023/6/12.
//

#ifndef ALGORITHM_TEMPLATE_STACK_QUEUE_H
#define ALGORITHM_TEMPLATE_STACK_QUEUE_H

/* 单调栈 ---------------------------------------
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;
int a[N];

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt--;
        if (tt) printf("%d ", stk[tt]);
        else printf("-1 ");
        stk[++tt] = x;
    }

    return 0;
}
 */

/* 单调队列 ------------------------------------------------
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int q[N], hh, tt = -1;
int a[N];

int main() {

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++; // 判断队头是否滑出了当前窗口

        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    printf ("\n");

    hh = 0; tt = -1;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++; // 判断队头是否滑出了当前窗口

        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    return 0;
}
*/

#endif //ALGORITHM_TEMPLATE_STACK_QUEUE_H
