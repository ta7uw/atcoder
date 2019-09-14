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
    int T;
    cin >> T;
    rep(t, T) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        bool found = false;
        rep(j, 10) {
            int red = -1;
            int blue = -1;
            string ans = "";
            rep(i, N) {
                int s = S[i] - '0';
                if (s < j && red <= s) {
                    ans += '1';
                    red = s;
                } else if (s >= j && blue <= s) {
                    ans += '2';
                    blue = s;
                } else if (s == j &&red!=-1 &&red <= s) {
                    red = s;
                    ans += '1';
                } else {
                    break;
                }
            }
            if (ans.size() == N) {
                cout << ans << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "-" << endl;
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
