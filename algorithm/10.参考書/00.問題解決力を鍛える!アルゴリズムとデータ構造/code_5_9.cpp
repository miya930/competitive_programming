#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main(void)
{
    int N;
    cin >> N;
    vector<vector<ll> > c(N+1, vector<ll>(N+1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> c[i][j];
        }
    }
    vector<ll> dp(N+1, INF);
    dp[0] = 0;

    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < i; j++) {
            chmin(dp[i], dp[j]+c[j][i]);
        }
    }
    cout << dp[N] << endl;

}
