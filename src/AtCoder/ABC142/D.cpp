#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    if (b == 0)return a;
    return gcd(b, a % b);
}

// 素因数分解
map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N] = 1;
    return res;
}

/**
 * D - Disjoint Set of Common Divisors
 * https://atcoder.jp/contests/abc142/tasks/abc142_d
 *
 * gcd(A, B)の素因数の数が答え
 */
void Main() {
    ll A, B;
    cin >> A >> B;
    ll g = gcd(A, B);
    map<ll, ll> pf = prime_factorize(g);
    cout << pf.size() + 1 << '\n';;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
