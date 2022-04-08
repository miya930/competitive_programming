#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool seen[200010];

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        seen[p[i]] = true;
        if (seen[cnt]) {
            while(seen[cnt]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
