#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n) ; i++)

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    rep(i, N) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        ans += (long long)distance(a.begin(), lower_bound(a.begin(), a.end(), b[i])) * distance(upper_bound(c.begin(), c.end(), b[i]), c.end());
    }
    cout << ans << endl;
}
