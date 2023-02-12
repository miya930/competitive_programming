#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    for (int i = 1; i < n; i++) {
        int l = 0;
        for (int k = 0; k < n; k++) {
            if (k+i >= n) continue;
            if (s[k] != s[k+i]) {
                l++;
            } else {
                break;
            }
        }
        cout << l << endl;
    }

    return 0;
}
