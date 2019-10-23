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
 * A. Yet Another Dividing into Teams
 * https://codeforces.com/contest/1249/problem/A
 *
 * A をソートして順に見ていき |ai - aj| = 1 を満たすペアがひとつでもあれば答えは 2 それ以外は 1
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
        vector<int> C;
        sort(A.begin(), A.end());
        rep(i, N) {
            int a = A[i];
            bool f = true;
            for (int b : B) {
                if (abs(b - a) == 1) {
                    f = false;
                }
            }
            if (f) {
                B.push_back(a);
            } else {
                C.push_back(a);
            }
        }
        if (C.size() >= 1) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
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
