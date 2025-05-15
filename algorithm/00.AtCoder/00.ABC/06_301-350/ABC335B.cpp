#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

struct pa {
    int x;
    int y;
    int z;
    pa(int x, int y, int z): x(x), y(y), z(z) { }
};

int main()
{
    int n;
    cin >> n;
    vector<pa> ans;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            for (int z = 0; z <= n; z++) {
                int sum = x + y + z;
                if (sum <= n) ans.push_back(pa(x, y, z));
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i].x << " " << ans[i].y << " " << ans[i].z << endl;

    return 0;
}
