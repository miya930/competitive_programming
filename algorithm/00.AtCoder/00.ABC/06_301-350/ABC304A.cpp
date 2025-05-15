#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> s[i] >> a[i];
    int idx = 0;
    int mi = 1001001001;
    for (int i = 0; i < n; i++) {
        if (mi > a[i]) {
            mi = a[i];
            idx = i;
        }
    }
    for (int i = idx; i < idx + n; i++) {
        cout << s[i%n] << endl;
    }

    return 0;
}
