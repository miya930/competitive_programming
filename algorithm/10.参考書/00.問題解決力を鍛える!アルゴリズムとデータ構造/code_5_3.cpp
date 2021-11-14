#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000007;

template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    vector<int> dp(N, INF);
    dp[0] = 0;

    for (int i = 1; i < N; ++i) {
        chmin(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        if (i > 1) chmin(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[N-1] << endl;
}
