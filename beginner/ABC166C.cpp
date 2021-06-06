#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n), a(m), b(m);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    vector<int> c(n, 1);

    for (int i = 0; i < m; ++i) {
        if (h[a[i]] < h[b[i]]) c[a[i]] = 0;
        else if (h[a[i]] > h[b[i]]) c[b[i]] = 0;
        else {
            c[a[i]] = 0;
            c[b[i]] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] == 1)
            ans++;
    }
    cout << ans << endl;
}
