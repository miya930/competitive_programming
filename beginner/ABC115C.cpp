#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF  = 1000000007;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    sort(h.begin(), h.end());

    int ans = INF;
    for (int i = 0; i < n-k+1; ++i) {
        int left = i;
        int right = k+i-1;

        ans = min(ans, h[right] - h[left]);
    }
    cout << ans << endl;
}
