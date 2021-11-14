#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{   
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<bool> vec(n, false);
    for (int a = 1; a <= 1000; a++) {
        for (int b = 1; b <= 1000; b++) {
            int sum = 4*a*b + 3*a + 3*b;

            for (int i = 0; i < n; ++i) {
                if (s[i] == sum) vec[i] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vec[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}
