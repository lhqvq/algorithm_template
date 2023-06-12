//
// Created by LHQvQ on 2023/6/12.
//

#ifndef ALGORITHM_TEMPLATE_TRIE_H
#define ALGORITHM_TEMPLATE_TRIE_H

/* trie 字符串统计 --------------------
#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        char op;
        string s;
        cin >> op >> s;
        if (op == 'I') insert(s);
        else cout << query(s) << endl;
    }

    return 0;
}
 */

/* 最大异或对（选两个异或，问最大值是多少）-------------------------------
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, M = 31 * N;

int n;
int son[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            p = son[p][!u];
            res = res * 2 + !u;
        } else {
            p = son[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}

int main() {

    scanf("%d", &n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        insert(x);

        int t = query(x);
        res = max(res, t ^ x);
    }

    printf("%d", res);

    return 0;
}
*/

#endif //ALGORITHM_TEMPLATE_TRIE_H
