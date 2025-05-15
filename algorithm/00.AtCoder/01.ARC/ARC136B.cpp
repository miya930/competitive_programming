#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> a, b;

void triswap(int v) {
    int tmp = a[v+2];
    a[v+2] = a[v+1];
    a[v+1] = a[v];
    a[v] = tmp; 
}

int main()
{
    cin >> n;
    a.resize(n); b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> aa = a, bb = b;
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (aa[i] != bb[i]) ok = false;
    }
    if (!ok) {
        cout << "No" << endl;
        return 0;
    }

    if (n == 3) {
        for (int j = 0; j < 3; j++) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    ok = false;
                }
            }
            triswap(0);

            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == a[i+1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n-2; i++) {
        if (a[i] == b[i]) continue;
        int idx;
        for (int j = 0; j < n; j++) {
            if (a[j] == b[i]) {
                idx = j;
                break;
            }
        }

        int diff = idx - i;
        while(diff > 0) {
            if (diff == 1) {
                triswap(idx-1);
                idx++;
                triswap(idx-2);
                idx -= 2;
                break;
            } else {
                triswap(idx-2);
                idx -= 2;
                diff = idx - i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
