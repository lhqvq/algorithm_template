//
// Created by LHQvQ on 2023/6/3.
//

#ifndef ALGORITHM_TEMPLATE_KMP_H
#define ALGORITHM_TEMPLATE_KMP_H

#include <iostream
#include <vector>
#include <string>

using namespace std;

int strStr(string s, string p) {
    if (p.empty()) return 0;
    int n = s.size(), m = p.size();
    s = ' ' + s, p = ' ' + p;

    vector<int> next(m + 1);
    for (int i = 2, j = 0; i <= m; i ++ ) {
        while (j && p[i] != p[j + 1]) j = next[j];
        if (p[i] == p[j + 1]) j ++ ;
        next[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i ++ ) {
        while (j && s[i] != p[j + 1]) j = next[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == m) return i - m;
    }

    return -1;
}

#endif //ALGORITHM_TEMPLATE_KMP_H
