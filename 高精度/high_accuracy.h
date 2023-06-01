//
// Created by LHQvQ on 2023/6/1.
//

#ifndef ALGORITHM_TEMPLATE_HIGH_ACCURACY_H
#define ALGORITHM_TEMPLATE_HIGH_ACCURACY_H

/* 高精度加法 ---------------------------------------
#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
vector<int> A, B;

vector<int> add(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;

    int t = 0; // 来自低位的进位
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);

    return C;
}

int main() {

    string a, b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}
*/

/* 高精度减法 ---------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

vector<int> A, B;
bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {

    vector<int> C;

    int t = 0; // 来自低位的借位
    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {

    string a, b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C = sub(A, B);

    if (cmp(A, B)) C = sub(A, B);
    else C = sub(B, A), printf("-");

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}
*/

/* 一个高精度乘一个 int ------------------------------------
#include <iostream>
#include <vector>
using namespace std;


const int N = 1e5 + 10;
vector<int> A;
int b;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int t = 0; // 来自低位的进位
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {

    string a;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    vector<int> C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}
*/

/* 一个高精度除一个 int ---------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
vector<int> A;
int b;

vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;

    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main() {

    string a;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    int r = 0;
    vector<int> C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    puts("");
    printf("%d", r);

    return 0;
}
*/

#endif //ALGORITHM_TEMPLATE_HIGH_ACCURACY_H
