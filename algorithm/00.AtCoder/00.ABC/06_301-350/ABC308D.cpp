#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    int h, w;
    string snuke = "snuke";
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    if (s[0][0] != 's') {
        cout << "No" << endl;
        return 0;
    }

    queue<pair<pair<int,int>, int>> que;
    que.push(make_pair(make_pair(0, 0), 0));
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    seen[0][0] = true;
    while(!que.empty()) {
        int vx = que.front().first.first;
        int vy = que.front().first.second;
        int cnt = que.front().second;
        que.pop();
        cnt++;
        cnt %= 5;
        
        for (int i = 0; i < 4; i++) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            if (nx >= h || nx < 0 || ny < 0 || ny >= w || s[nx][ny] != snuke[cnt]) continue;
            if (seen[nx][ny]) continue;

            que.push(make_pair(make_pair(nx, ny), cnt));
            seen[nx][ny] = true;

            if (nx == h-1 && ny == w-1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
