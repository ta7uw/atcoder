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
 * B2. Social Network (hard version)
 * https://codeforces.com/contest/1234/problem/B2
 * dequeとsetを使ってすでに登録されいるidを保持する
 * setだとO(logN)で存在確認ができる
 * unordered_setを使う場合はhashの衝突に注意する
 */
void Main() {
    int N, K;
    cin >> N >> K;
    vector<ll> ids(N);
    rep(i, N) cin >> ids[i];
    deque<ll> que;
    set<ll> used;
    rep(i, N) {
        ll id = ids[i];
        if (used.find(id) != used.end()) {
            continue;
        }else{
            if (que.size() >= K) {
                ll last = que.back();
                que.pop_back();
                used.erase(last);
            }
            used.insert(id);
            que.push_front(id);
        }
    }
    cout << que.size() << '\n';
    rep(i, que.size()) {
        cout << que[i] << " ";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
