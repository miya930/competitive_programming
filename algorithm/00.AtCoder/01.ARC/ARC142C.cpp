#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> dist1(n+1, 0), dist2(n+1, 0);
    for (int i = 3; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;

        int x;
        cin >> x;
        dist1[i] = x;
    }
    for (int i = 3; i <= n; i++) {
        if (i == 2) continue;
        cout << "? " << 2 << " " << i << endl;

        int x;
        cin >> x;
        dist2[i] = x;
    }

    int exist = -1;
    for (int i = 1; i <= n; i++) {
        if (i == 2) continue;

        if (dist2[i] == 1) {
            exist = i;
            break;
        }
    }

    if (exist == -1) {
        cout << "! 1" << endl;
        return 0;
    }

    if (dist1[exist] == 1) {
        cout << "! 2" << endl;
        return 0;
    }

    int idx = -1;
    for (int i = 3; i <= n; i++) {
        if (dist1[i] == 1) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "! 1" << endl;
        return 0;
    }

    cout << "? " << idx << " " << exist << endl;
    int x;
    cin >> x;

    if (x > dist2[idx]) {
        cout << "! " << dist1[exist] - 1 << endl;
    } else {
        cout << "! " << dist1[exist] + 1 << endl;
    }


    return 0;
}
