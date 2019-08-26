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

map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N] = 1;
    return res;
}


void Main() {
    int N;
    cin >> N;
    auto res = prime_factorize(20);
    unordered_map<ll, ll> tar;
    for (int i = 1; i <= N; ++i) {
        for (auto tmp : prime_factorize(i)){
            if (tar.find(tmp.first) != tar.end()){
                tar[tmp.first] += tmp.second;
            }else{
                tar[tmp.first] = tmp.second;
            }
        }
    }
    ll ans = 1;
    for(auto t: tar) {
        ans *= (t.second + 1);
        ans %= MOD;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
