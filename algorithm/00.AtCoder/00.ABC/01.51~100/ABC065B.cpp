#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    
    vector<bool> seen(n, false);
    seen[0] = true;
    int v = 0;
    int cnt = 1, ans = 0;

    while(1) {
        int nv = a[v];
        if (seen[nv]) {
            ans = -1;
            break;
        } else if (nv == 1) {
            ans = cnt;
            break;
        }
        cnt++;
        seen[nv] = true;
        v = nv;
    }

    cout << ans << endl;
    return 0;
}
