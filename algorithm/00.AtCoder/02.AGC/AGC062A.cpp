#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        string s;
        cin >> n >> s;

        if (s[n-1] == 'A') {
            cout << 'A' << endl;
        } else {
            bool isb = false;
            for (int i = 0; i < n-1; i++) {
                if (s[i] == 'B' && s[i+1] == 'A') {
                    isb = true;
                    break;
                }
            }
            if (isb) cout << 'A' << endl;
            else cout << 'B' << endl;
        }
    }

    return 0;
}
