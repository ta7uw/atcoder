#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define rep2(i, m, n) for(int i=m;i<(n);i++)
#define rrep(i, n, m) for(int i=n;i>=(m);i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    unordered_map<string, ll> dic;
    for (int i = 0; i < N; ++i) {
        string s = S[i];
        sort(sk.begin(), s.end());
        dic[s] += 1;
    }
    ll ans = 0;
    for (auto p : dic) {
        if (p.second > 1) {
            ans += (p.second * (p.second - 1)) / 2;
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
