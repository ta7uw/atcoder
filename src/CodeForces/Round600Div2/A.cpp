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

/**
 *  A. Single Push
 * https://codeforces.com/contest/1253/problem/A
 *
 * A と B の差が [0, 0, ...,k, ... k, 0, 0]のようなかたちをしているか判定。
 * あらかじめ差を求めておいて、ランレングス圧縮を使うと楽
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        rep(i, n) cin >> A[i];
        rep(i, n) cin >> B[i];

        bool use = false;
        bool sec = false;
        bool f = false;
        int diff = -1;
        rep(i, n) {
            if (A[i] == B[i]) {
                if (!use) {
                    continue;
                }else{
                    sec = true;
                }
            } else {
                if (sec) {
                    f = true;
                    break;
                }
                use = true;
                if (A[i] > B[i]) {
                    f = true;
                    break;
                }
                if (diff == -1) {
                    diff = B[i] - A[i];
                } else {
                    if (B[i] - A[i] == diff) {
                        continue;
                    } else {
                        f = true;
                        break;
                    }
                }
            }
        }
        if (f) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
