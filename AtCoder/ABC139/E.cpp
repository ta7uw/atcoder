
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
    int N;
    cin >> N;
    vector<deque<ll>> items(N);
    rep(i, N) {
        rep(j, N - 1) {
            int a;
            scanf("%d", &a);
            items[i].push_back(a);
        }
    }

    ll ans = 0;

    while (true) {
        vector<bool> visited(N+1, false);
        bool flag = false;
        bool all_done = true;
        rep(j, N) {
            if (visited[j+1]) {
                continue;
            }
            if (!items[j].empty()) {
                ll t = items[j].front();
                if (!visited[t] && !items[t - 1].empty() && j + 1 == items[t - 1].front()) {
                    visited[j+1] = true;
                    visited[t] = true;
                    items[j].pop_front();
                    items[t - 1].pop_front();
                    flag = true;
                }
            }
            if (!items[j].empty()){
                all_done = false;
            }
        }
        if (flag) {
            ans++;
        }else{
            cout << -1 << endl;
            return;
        }
        if (all_done) {
            cout << ans << endl;
            break;
        }
        if (ans > 1e4/2){
            cout << N*(N-1)/2 << endl;
            return;
        }

    }

}

int main() {
    Main();
}
