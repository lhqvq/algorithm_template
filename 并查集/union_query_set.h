//
// Created by LHQvQ on 2023/6/12.
//

#ifndef ALGORITHM_TEMPLATE_UNION_QUERY_SET_H
#define ALGORITHM_TEMPLATE_UNION_QUERY_SET_H

/* 并查集 ----------------------
#include <iostream>
using namespace std;

const int N = 100010;

int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        char op[2];
        int x, y;
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'M') {
            p[find(x)] = find(y);
        } else {
            if (find(x) == find(y)) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
 */




#endif //ALGORITHM_TEMPLATE_UNION_QUERY_SET_H
