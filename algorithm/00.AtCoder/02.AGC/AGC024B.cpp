#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> p(200005);

int main()
{
    int n;
    cin >> n;
    
    for (int i  = 0; i < n; ++i) {
        int a; cin >> a;
        p[a] = p[a-1] + 1;
    }
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        ans = max(ans, p[i]);
    }
    cout << n - ans << endl;

    return 0;
}
