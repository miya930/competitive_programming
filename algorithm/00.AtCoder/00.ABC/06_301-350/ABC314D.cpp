#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    string s;
    cin >> n >> s >> Q;

    vector<int> t(Q), x(Q);
    vector<char> c(Q);

    for (int i = 0; i < Q; i++) {
        cin >> t[i] >> x[i] >> c[i];
    }

    int las2 = -1, las3 = -1;
    for (int i = 0; i < Q; i++) {
        if (t[i] == 2) las2 = i;
        else if (t[i] == 3) las3 = i;
    }

    if (las2 == -1 && las3 == -1) {
        for (int i = 0; i < Q; i++) {
            x[i]--;
            s[x[i]] = c[i];
        }
    } else if (las2 > las3) {
        for (int i = 0; i < las2; i++) {
            if (t[i] == 1) {
                x[i]--;
                s[x[i]] = c[i];
            }
        }
        int off = 'a' - 'A';
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') s[i] += off;
        }
        for (int i = las2 + 1; i < Q; i++) {
            if (t[i] == 1) {
                x[i]--;
                s[x[i]] = c[i];
            }            
        }

    } else {
        for (int i = 0; i < las3; i++) {
            if (t[i] == 1) {
                x[i]--;
                s[x[i]] = c[i];
            }
        }
        for (int i = 0; i < n; i++) {
            int off = 'a' - 'A';
            if (s[i] >= 'a' && s[i] <= 'z') s[i] -= off;
        }
        for (int i = las3 + 1; i < Q; i++) {
            if (t[i] == 1) {
                x[i]--;
                s[x[i]] = c[i];
            }            
        }
    }
    cout << s << endl;
    return 0;
}
