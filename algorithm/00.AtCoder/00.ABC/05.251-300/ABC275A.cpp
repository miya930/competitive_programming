#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int ma = 0, ans;
    for (int i = 0; i < n; ++i) {
        if (h[i] > ma) {
            ans = i;
            ma = h[i];
        }
    }    

    cout << ans+1 << endl;
    return 0;
}
