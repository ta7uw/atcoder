#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
    int N, L;
    cin >> N >> L;

    vector<int> res;
    rep(i, N) {
        res.push_back(abs(L + i));
    }

    sort(res.begin(), res.end());
    ll ans = 0;
    rep2(i, 0, N) {
        if (abs(L + i) == res[0]){
            continue;
        }
        ans += L + i;
    }
    cout << ans << endl;

}
