#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };


int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    deque<pii> deq;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[a][b] = 0;
    deq.push_back(make_pair(a, b));
    while(!deq.empty()) {
        int y = deq.front().first;
        int x = deq.front().second;
        deq.pop_front();

        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 2; j++) {
                int nx = x + dx[i] * j;
                int ny = y + dy[i] * j;
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

                if (s[ny][nx] == '.') {
                    if (j == 2) continue;
                    if (dist[ny][nx] > dist[y][x]) {
                        dist[ny][nx] = dist[y][x];
                        deq.push_front(make_pair(ny, nx));
                    }
                } else {
                    if (dist[ny][nx] > dist[y][x] + 1) {
                        dist[ny][nx] = dist[y][x] + 1;
                        deq.push_back(make_pair(ny, nx));
                    }
                }
            }
        }
    }
    cout << dist[c][d] << endl;
    return 0;
}
