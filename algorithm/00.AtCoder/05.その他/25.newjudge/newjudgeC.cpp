#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<bool> seen(2*n+1, false);
    priority_queue<int> que;
    for (int i = 0; i < 2*n+1; i++) {
        que.push(i);
    }

    while(1) {
        while(1) {
            int v = que.top();
            que.pop();
            if (seen[v]) continue;
            else {
                seen[v] = true;
                cout << v + 1 << endl;
                break;
            }
        }
        int x;
        cin >> x;
        x--;
        if (x == -1) {
            return 0;
        }
        seen[x] = true;
    }

    return 0;
}
