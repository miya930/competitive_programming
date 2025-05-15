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


int main()
{
    int n;
    cin >> n;

    for (int i = n; i < 1000; i++) {

        int h = (i / 100) % 10;
        int j = (i / 10) % 10;
        int ii = i % 10;
        if (h*j == ii) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
