#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int dx[] = {-1, 0, 1 ,0};
int dy[] = {0, -1, 0, 1};

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) cin >> a[i];
    vector<pair<char,pair<int,int>>> pa;
    pair<int,int> s, g;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '>' || a[i][j] == '<' || a[i][j] == 'v' || a[i][j] == '^') {
                pa.push_back(make_pair(a[i][j], make_pair(i, j)));
            }
            if (a[i][j] == 'S') {
                s.first = i;
                s.second = j;
            }
            if (a[i][j] == 'G') {
                g.first = i;
                g.second = j;
            }
        }
    }

    for (int i = 0; i < pa.size(); i++) {
        char c = pa[i].first;
        int u = pa[i].second.first;
        int v = pa[i].second.second;

        if (c == '>') {
            while(1) {
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                v++;
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                if (a[u][v] == '#' || a[u][v] == '>' || a[u][v] == '<' || a[u][v] == 'v' || a[u][v] == '^') break;
                a[u][v] = 'x';
            }
        } else if (c == '<') {
            while(1) {
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                v--;
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                if (a[u][v] == '#' || a[u][v] == '>' || a[u][v] == '<' || a[u][v] == 'v' || a[u][v] == '^') break;
                a[u][v] = 'x';
            }
        } else if (c == 'v') {
            while(1) {
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                u++;
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                if (a[u][v] == '#' || a[u][v] == '>' || a[u][v] == '<' || a[u][v] == 'v' || a[u][v] == '^') break;
                a[u][v] = 'x';   
            }
         
        } else if (c == '^') {
            while(1) {
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                u--;
                if (u < 0 || u >= h || v < 0 || v >= w) break;
                if (a[u][v] == '#' || a[u][v] == '>' || a[u][v] == '<' || a[u][v] == 'v' || a[u][v] == '^') break;
                a[u][v] = 'x';    
            }
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[s.first][s.second] = 0;
    queue<pair<int,int>> que;
    que.push(s);

    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (a[nx][ny] == '#' || a[nx][ny] == 'x' || a[nx][ny] == '<' ||a[nx][ny] == '>' || a[nx][ny] == 'v' || a[nx][ny] == '^') continue;
            if (dist[nx][ny] != inf) continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            que.push(make_pair(nx, ny));
        }
    }

    if (dist[g.first][g.second] == inf) cout << -1 << endl;
    else cout << dist[g.first][g.second] << endl;

    return 0;
}
