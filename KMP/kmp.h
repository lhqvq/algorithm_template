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


    // KMP 模板
    vector<int> calc_max_match(string s) {
        vector<int> match(s.length());
        int c = 0;
        for (int i = 1; i < s.length(); i++) {
            char v = s[i];
            while (c && s[c] != v) {
                c = match[c - 1];
            }
            if (s[c] == v) {
                c++;
            }
            match[i] = c;
        }
        return match;
    }

    // KMP 模板
    // 返回 text 中出现了多少次 pattern（允许 pattern 重叠）
    int kmp_search(string text, string pattern) {
        vector<int> match = calc_max_match(pattern);
        int match_cnt = 0, c = 0;
        for (int i = 0; i < text.length(); i++) {
            char v = text[i];
            while (c && pattern[c] != v) {
                c = match[c - 1];
            }
            if (pattern[c] == v) {
                c++;
            }
            if (c == pattern.length()) {
                match_cnt++;
                c = match[c - 1];
            }
        }
        return match_cnt;
    }


#endif //ALGORITHM_TEMPLATE_KMP_H
