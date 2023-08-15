#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n >> Q;

    priority_queue<int, vector<int>, greater<int>> notcalled, notgo;
    vector<bool> go(n+1, false);

    for (int i = 0; i < n; i++) {
        notcalled.push(i);
    }

    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;

        if (t == 1) {
            int v = notcalled.top();
            notcalled.pop();

            notgo.push(v);
        } else if (t == 2) {
            int x;
            cin >> x;
            x--;

            go[x] = true;

        } else {
            while(1) {
                int v = notgo.top();

                if (go[v]) {
                    notgo.pop();
                    continue;
                } else {
                    cout << v + 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
