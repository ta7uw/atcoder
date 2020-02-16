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

void Main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    string ans = "";
    set<int> used;
    map<string, vector<ll>> pal;
    rep(i, N) {
        string s = S[i];
        string t = s;
        reverse(t.begin(), t.end());
        if (t == s) {
            pal[s].push_back(i);
        }
    }
    for (auto p: pal) {
        if (p.second.size() % 2 == 1) {
            ans = p.first;
            used.insert(p.second[0]);
            break;
        }
    }

    rep(i, N) {
        if (used.count(i) >= 1) {
            continue;
        } else {
            string s = S[i];
            rep2(j, i + 1, N) {
                string t = S[j];
                reverse(t.begin(), t.end());
                if (s == t) {
                    used.insert(i);
                    used.insert(j);
                    reverse(t.begin(), t.end());
                    ans = s + ans + t;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
