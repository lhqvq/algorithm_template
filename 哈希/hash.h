//
// Created by LHQvQ on 2023/6/12.
//

#ifndef ALGORITHM_TEMPLATE_HASH_H
#define ALGORITHM_TEMPLATE_HASH_H

/*
// 拉链法
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;

void insert(int x) {
    int u = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[u];
    h[u] = idx++;
}

bool find(int x) {
    int u = (x % N + N) % N;
    for (int i = h[u]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }

    return false;
}

int main() {

    int n;
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I') insert(x);
        else
        {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
*/

/* 开放定址法
#include <iostream>
#include <cstring>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) t = 0;
    }
    return t;
}

int main() {

    memset(h, 0x3f, sizeof h);

    int n;
    scanf("%d", &n);

    while (n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I') h[find(x)] = x;
        else
        {
            if (h[find(x)] != null) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
*/


/* 字符串哈希 -------------------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

int n, m;
ULL h[N], p[N];
char str[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {

    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);

    p[0] = 1; // P 的 0 次方
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i] - 'a' + 1;
        p[i] = p[i - 1] * P;
    }

    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}
*/

#endif //ALGORITHM_TEMPLATE_HASH_H
