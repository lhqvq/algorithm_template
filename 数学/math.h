//
// Created by LHQvQ on 2023/6/16.
//

#ifndef ALGORITHM_TEMPLATE_MATH_H
#define ALGORITHM_TEMPLATE_MATH_H

// 判断质数 -------------------------------------
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// 分解质因数 ---------------------------------------------
void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            cout << i << " " << cnt << endl;
        }
    }

    if (x > 1) cout << x << " " << 1 << endl;
    cout << endl;
}

// 筛质数(1~n 中的质数个数) -------------------------------------------------
const int N = 1000010;

int primes[N], cnt;
bool st[N];

// 朴素筛法
void get_primes_1(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

// 埃氏筛法
void get_primes_2(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}

// 欧拉筛法
void get_primes_3(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}



// 试除法求所有约数 ---------------------------------------
vector<int> get_divisors(int x) {
    vector<int > res;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


// 约数个数(n个数，求这些数的乘积的约数个数) ----------------------------------------------------
typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int main() {

    int n;
    cin >> n;

    unordered_map<int , int> primes;

    while (n--) {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1) primes[x]++;
    }

    LL res = 1;
    for (auto &[k, v] : primes) res = res * (v + 1) % mod;

    cout << res << endl;

    return 0;
}



// 约数之和(n个数，求这些数的乘积的约数之和) ----------------------------------------------
typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> primes;

    while (n -- )
    {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i ++ )
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++ ;
            }

        if (x > 1) primes[x] ++ ;
    }

    LL res = 1;
    for (auto &[k, v] : primes)
    {
        LL a = k, b = v;
        LL t = 1;
        while (b -- ) t = (t * a + 1) % mod;
        res = res * t % mod;
    }

    cout << res << endl;

    return 0;
}


// 最大公约数
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}


// 欧拉函数(n 个数，求每个数的欧拉函数，欧拉函数是 1~n 中与 n 互质的数的个数) ------------------------------------------
int main() {

    int n;
    scanf("%d", &n);

    while (n--) {
        int a;
        scanf("%d", &a);

        int res = a;
        for (int i = 2; i <= a / i; i++) {
            if (a % i == 0) {
                res = res / i * (i - 1);
                while (a % i == 0) a /= i;
            }
        }
        if (a > 1) res = res / a * (a - 1);

        printf("%d\n", res);
    }

    return 0;
}



// 筛法求欧拉函数（欧拉函数是 1~n 中与 n 互质的数的个数） --------------------------------------------------------------
typedef long long ll;

const int N = 1000010;

int primes[N], cnt;
bool st[N];
int phi[N];

ll get_eulers(int n) {
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];;
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) res +=phi[i];

    return res;
}



// 快速幂 -------------------------------------------------------------------
typedef long long ll;

// a ^ k % p
int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}








#endif //ALGORITHM_TEMPLATE_MATH_H
