#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(3);
    vector<int> tab(301, 0);
    bool ng = false;
    for (int i = 0; i < 3; ++i) {
        cin >> vec[i];
        tab[vec[i]]++;
        if (vec[i] == n) ng = true;
    }

    int now = 0;
    int cnt = 0;
    while (now < n) {
        int next = now + 3;
        bool ok = true;
        cnt++;
        
        int backcnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (tab[next]) {
                next--;
                backcnt++;
            } else {
                break;
            }
        }

        if (backcnt == 3) {
            ng = true;
            break;
        }

        if (next >= n) break;
        
        now = next;
    }

    if (cnt > 100) ng = true;

    if (!ng) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
