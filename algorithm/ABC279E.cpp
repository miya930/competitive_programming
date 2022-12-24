#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> sumr(m+1, 0), suml(m+1, 0);

    int cur = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] == cur) {
            cur++;
            suml[i+1] = suml[i] + 1;
        }
        if (i+1 < m && a[i+1] == cur) {
            cur--;
            suml[i+1] = sum[i] - 1;
        }
    }

    cur = m-1;
    for (int i = m-1; i >= 0; i--) {
        if ()
    }

    return 0;
}
