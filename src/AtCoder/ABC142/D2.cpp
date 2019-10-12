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

// 約数列挙
vector<ll> divisor(ll N) {
    vector<ll> res;
    for (ll i = 1L; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            ll j = N / i;
            if (j != i) {
                res.push_back(j);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

/**
 * D - Disjoint Set of Common Divisors
 * https://atcoder.jp/contests/abc142/tasks/abc142_d
 * A, B それぞれの約数を列挙して共通のものを取り出すことでAとBの公約数を手に入れる
 * 公約数を小さい順に見ていき、すでに使って公約数で割り切れるものがなければ追加していく。
 * 計算量の見積もりが難しいので D.cppの方がよさそう
 */
void Main() {
    ll A, B;
    cin >> A >> B;
    vector<ll> a_d = divisor(A);
    vector<ll> b_d = divisor(B);

    vector<ll> target;
    rep(i, a_d.size()) {
        ll a = a_d[i];
        rep(j, b_d.size()) {
            ll b = b_d[j];
            if (a == b) {
                target.push_back(a);
                break;
            }
        }
    }

    vector<ll> used;
    sort(target.begin(), target.end());
    for (ll t : target) {
        if (used.size() == 0) {
            used.push_back(t);
        } else {
            bool flg = true;
            for (ll u : used) {
                if (gcd(t, u) != 1) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                used.push_back(t);
            }
        }
    }

    cout << used.size() << '\n';

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
