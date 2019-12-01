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
    int N, K;
    cin >> N >> K;
    int ans = (N - 1) * (N - 2) / 2;
    vector<pair<int, int>> res;
    rep2(i, 2, N + 1) {
        res.emplace_back(make_pair(1, i));
    }
    if (ans < K) {
        cout << -1 << endl;
        return 0;
    }
    if (ans != K) {
        for (int i = 2; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (i == j) {
                    continue;
                } else {
                    res.emplace_back(make_pair(i, j));
                    ans -= 1;
                    if (ans == K) {
                        break;
                    }
                }
            }
            if (ans == K) {
                break;
            }
        }
    }
    cout << res.size() << endl;
    rep(i, res.size()) {
        cout << res[i].first << " " << res[i].second << endl;
    }
}
