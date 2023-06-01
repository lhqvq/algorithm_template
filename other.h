//
// Created by LHQvQ on 2023/6/1.
//

#ifndef ALGORITHM_TEMPLATE_OTHER_H
#define ALGORITHM_TEMPLATE_OTHER_H

// 求二进制中最低位的 1
int lowbit(int x) {
    return x & -x;
}


/* 离散化
 * 无限长数轴，先 n 次某个位置 x 上的数加 c，接下来 m 次询问，求 l 和 r 的区间和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int a[N], s[N];
vector<int> alls; // 待离散化的数据
vector<PII> adds, querys;
int n, m;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return r + 1;
}

int main() {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x, c;
        scanf("%d%d", &x, &c);

        adds.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);

        querys.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto &add : adds) {
        int index = find(add.first);
        a[index] += add.second;
    }

    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    for (auto &q : querys) {
        int l = find(q.first);
        int r = find(q.second);
        printf ("%d\n", s[r] - s[l - 1]);
    }

    return 0;
}
*/

/* 区间合并，求合并后的区间数 ---------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

vector<PII> segs;
int n;

void mergeSegs(vector<PII> &segs) {

    vector<PII> res;

    sort(segs.begin(), segs.end());

    int beg = -2e9, end = -2e9;
    for (auto &seg : segs) {
        if (seg.first > end) {
            if (beg != -2e9) res.push_back({beg, end});
            beg = seg.first;
            end = seg.second;
        } else {
            end = max(end, seg.second);
        }
    }

    if (beg != -2e9) res.push_back({beg, end});

    segs = res;
}

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int beg, end;
        scanf("%d%d", &beg, &end);
        segs.push_back({beg, end});
    }

    mergeSegs(segs);

    printf("%d", segs.size());

    return 0;
}
*/

#endif //ALGORITHM_TEMPLATE_OTHER_H
