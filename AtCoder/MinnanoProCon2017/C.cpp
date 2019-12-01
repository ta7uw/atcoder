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
    vector<int> A(K);
    rep(i, K) cin >> A[i];
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    if (N == K) {
        cout << " " << endl;
        return;
    }

    int first = A[0] - 1;
    string base = S[first];
    vector<int> V(N);
    rep(i, N) {
        if (i == first) {
            V[i] = base.size();
        } else {
            int cnt = 0;
            rep(j, min(base.size(), S[i].size())) {
                if (S[i][j] == base[j]) {
                    cnt++;
                } else {
                    break;
                }
            }
            V[i] = cnt;
        }
    }

    int min_num = MOD;
    int max_num = 0;
    unordered_set<int> s(A.begin(), A.end());
    rep(i, N) {
        if (s.find(i + 1) != s.end()) {
            min_num = min(min_num, V[i]);
        } else {
            max_num = max(max_num, V[i]);
        }
    }

    if (max_num < min_num) {
        cout << base.substr(0, max_num + 1) << endl;
    } else {
        cout << -1 << endl;
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
