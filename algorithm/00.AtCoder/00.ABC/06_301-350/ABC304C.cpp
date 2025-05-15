#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    for (int i = 0; i <n; i++) cin >> x[i] >> y[i];

    vector<bool> ill(n, false);
    ill[0] = true;
    queue<pair<int,int>> que;
    que.push(make_pair(x[0], y[0]));
    while(!que.empty()) {
        int vx = que.front().first;
        int vy = que.front().second;
        que.pop();
        for (int i = 1; i < n; i++) {
            if (ill[i]) continue;
            int diff = (x[i] - vx)*(x[i] - vx) + (y[i] - vy)*(y[i] - vy);
            int dd = d*d;
            if (diff <= dd) {
                ill[i] = true;
                que.push(make_pair(x[i], y[i]));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ill[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
