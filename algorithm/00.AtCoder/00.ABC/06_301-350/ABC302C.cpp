#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;

    do {
        int cnt = 0;
        bool isok = true;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m; j++) {
                if (s[a[i]][j] != s[a[i+1
                ]][j]) cnt++;
            }
            if (cnt != 1) isok = false;
            cnt = 0;
        }

        if (isok) {
            cout << "Yes" << endl;
            return 0;
        }

    } while(next_permutation(a.begin(), a.end()));

    cout << "No" << endl;

    return 0;
}
