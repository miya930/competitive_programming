#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
#define rep(i,n) for(int i = 0; i < n; ++i)

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    sort(b.begin(), b.end());
    vector<ll> t(N, 0);

    ll left = 0, right = INF;
    while(right - left > 1) {
        ll x = (right+left)/2;

        rep(i, N) t[i] = x/a[i];                                                // t[i](0<=i<N)以下となるbをすべて足し上げるため
        int tmp = 0;                                                            // → このようなbを求めるために二分探索を用いる
        rep(i, N) tmp += upper_bound(b.begin(), b.end(), t[i]) - b.begin();     // a*b <= Xを満たすbの個数tmpを計算
        if (tmp >= K) right = x;                                                // tmp >= Kを満たす最小のtmpが求まるまで続く
        else left = x;
    }
    cout << right << endl;
}
