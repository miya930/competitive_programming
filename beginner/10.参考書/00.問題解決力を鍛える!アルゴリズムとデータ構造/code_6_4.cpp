#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, m) for(int i = 0; i < (m); i++)
const int INF = 20000000;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    // 暫定最小値を格納する変数
    int min_value = INF;
    
    sort(b.begin(), b.end());

    b.push_back(INF);

    rep(i, N) {
        auto iter = lower_bound(b.begin(), b.end() ,K - a[i]);

        // イテレータの示す値を取り出す
        int val = *iter;

        if (min_value > a[i] + val)
            min_value = a[i] + val;
    }
    cout << min_value << endl;
}
