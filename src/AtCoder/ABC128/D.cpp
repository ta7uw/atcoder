#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector<vector<ll>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N, K;
    cin >> N >> K;
    deque<int> queue;
    rep(i, N) {
        int v;
        cin >> v;
        queue.push_back(v);
    }
    ll ans = 0;
    rep(i, min(K + 1, N + 1)) {
        rep(j, min(N-i+1, K-i+1)) {
            int remain = K - i - j;
            deque<int> que = queue;
            vector<int> tmp;
            rep(a, i) {
                tmp.push_back(que.front());
                que.pop_front();
            }
            rep(a, j) {
                tmp.push_back(que.back());
                que.pop_back();
            }
            sort(tmp.begin(), tmp.end());
            ll num = 0;
            for (int q : tmp) {
                if (q <= 0 && remain >= 1) {
                    remain --;
                    continue;
                }
                num += q;
            }
            ans = max(ans, num);
            remain += j;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
