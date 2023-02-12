#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{  
    int n, k;
    cin >> n >> k;
    vector<string> s(k);
    for (int i = 0 ; i < n; i++) {
        if (i < k) cin >> s[i];
        else {
            string str;
            cin >> str;
        }
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < k; i++) {
        cout << s[i] << endl;
    }

    return 0;
}
