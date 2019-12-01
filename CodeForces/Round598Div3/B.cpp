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
 * B. Minimize the Permutation
 * https://codeforces.com/contest/1256/problem/B
 *
 * 交換する際に使用する index は 1 度しか使えないので
 * 現在の位置 ( 先頭からスタート ) から末尾までで最小の値をできる限り前にもってくる操作を繰り返し行う。
 * 貪欲法
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        int N;
        cin >> N;
        vector<int> A(N);
        rep(i, N) cin >> A[i];

        vector<int> B;
        int tar = 1;
        int idx = 0;
        rep(i, N) {
            if (A[i] == tar) {
                if (B.empty()) {
                    B.push_back(tar);
                }else{
                    int b = B[B.size()-1];
                    if (b  > tar) {
                        B[B.size()-1] = tar;
                        B.push_back(b);
                    }else{
                        B.push_back(tar);
                    }
                }
                rep2(j, idx, i) {
                    B.push_back(A[j]);
                }
                idx = i + 1;
                tar = MOD;
                rep2(j, i+1, N) {
                    tar = min(tar, A[j]);
                }
            }
        }
        rep(i, N) {
            cout << B[i] << ' ';
        }
        cout << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
