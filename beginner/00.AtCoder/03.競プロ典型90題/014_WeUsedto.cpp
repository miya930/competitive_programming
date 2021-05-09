#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void)
{
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll res = 0;
    rep(i, N) {
        res += abs(a[i]-b[i]);
    }
    cout << res << endl;
}
