#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> count(n, 0);
    for (int q = 0; q < Q; q++) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            count[x]++;
        } else if (t == 2) {
            count[x] += 2;
        } else {
            if (count[x] >= 2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
