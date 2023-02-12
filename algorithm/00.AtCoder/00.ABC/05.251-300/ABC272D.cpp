#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> pa;
    for (int a = -1000; a <= 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            if (a*a+b*b == m) {
                pa.push_back(make_pair(a, b));
            }
        }
    }

    queue<pair<int,int>> que;
    vector<vector<int>> dist(n+100, vector<int>(n+100, -1));

    dist[0][0] = 0;
    que.push(make_pair(0, 0));
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (auto p : pa) {
            int a = p.first;
            int b = p.second;

            int nx = x + a;
            int ny = y + b;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            que.push(make_pair(nx, ny));
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            cout << dist[x][y] << " ";
        }
        cout << endl;
    }

    return 0;
}
