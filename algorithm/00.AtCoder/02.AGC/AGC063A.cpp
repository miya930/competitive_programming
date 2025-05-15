#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a, b;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') b.push_back(i);
        else a.push_back(i);
    }

    int ca = 0, cb = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) {
            if (a.size() <= ca) {
                cout << "Alice" << endl;
            } else {
                int idx = a[ca];
                seen[idx] = true;

                while(seen[now]) now++;
                if (s[now] == 'A') cout << "Alice" << endl;
                else cout << "Bob" << endl;

                ca++;
            }
        } else {
            if (b.size() <= cb) {
                cout << "Bob" << endl;
            } else {
                int idx = b[cb];
                seen[idx] = true;

                while(seen[now]) now++;
                if (s[now] == 'A') cout << "Alice" << endl;
                else cout << "Bob" << endl;                

                cb++;
            }
        }
    }

    return 0;
}
