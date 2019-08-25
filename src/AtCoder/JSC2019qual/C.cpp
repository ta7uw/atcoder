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
    string S;
    cin >> N >> S;
    ll cnt = 0;
    ll ans = 1;

    for (int i = 0; i < 2 * N; ++i) {
        if (S[i] == 'W') {
            if (cnt == 0) {
                cout << 0 << endl;
                return;
            }
            if(cnt%2 == 0){
                ans *= cnt;
                ans %= MOD;
                cnt --;
            }else{
                cnt ++;
            }
        } else {
            if (cnt % 2 == 0){
                cnt ++;
            }else{
                ans *= cnt;
                ans %= MOD;
                cnt --;
            }
        }
    }

    if (cnt != 0) {
        cout << 0 << endl;
    } else {
        for (ll i = 1; i <= N; ++i) {
            ans *= i;
            ans %= MOD;
        }
        cout << ans << endl;
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
