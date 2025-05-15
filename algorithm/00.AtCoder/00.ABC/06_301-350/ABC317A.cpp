#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, h, x;
    cin >> n >> h >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    for (int i = 0; i < n; i++) {
        int tmp = h + p[i];
        if (tmp >= x) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
