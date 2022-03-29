#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<int> x(5);
    for (int i = 0; i < 5; ++i) cin >> x[i];

    int ans;
    for (int i = 0; i < 5; ++i) {
        if (x[i] == 0) ans = i+1;
    }

    cout << ans << endl;
    return 0;
}
