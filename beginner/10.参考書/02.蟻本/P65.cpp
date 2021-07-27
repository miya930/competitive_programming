#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;

int dp[100];
int n;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
}

void solve() {
    fill(dp, dp+n, INF);
    for (int i = 0; i < n; ++i) {
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    
    

}
