#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
const int INF = 1000000007;

vector<vector<bool> > used;
vector<string> field;
stack<pair<int, int> > st;
int h, w, min_cnt = INF;
int ans = INF;

int pun(int cnt, stack<pair<int, int> > st) {
    int res = 0;
    vector<pair<int, int> > vec;

    if (cnt == 0) return 0;

    while(!st.empty()) {
         int x = st.top().first;
         int y = st.top().second;
         st.pop();
         vec.push_back(make_pair(x, y));
    }

    for (int i = 1; i < (int)vec.size(); ++i) {
        int dif_x = abs(vec[i].first - vec[i - 1].first);
        int dif_y = abs(vec[i].second - vec[i - 1].second);

        if (dif_x < 2 || dif_y < 2) {
            res++;
            i++;
        }
        else {
            res++;
        }
    }
    return res;
}


void dfs(int sx, int sy, int cnt) {
    if (sx == h - 1 && sy == w - 1) {
        ans = min(ans, pun(cnt, st));
        min_cnt = min(min_cnt, cnt);
        return;
    }

    used[sx][sy] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = sx + dx[i], ny = sy + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w || used[nx][ny] == true) continue;
        if (field[nx][ny] == '#') {
            st.push(make_pair(nx, ny));
            cnt++;
        }
        if (min_cnt < cnt) continue;

        dfs(nx, ny, cnt);

        if (field[nx][ny] == '#') {
            st.pop();
            cnt--;
        }
    }

    used[sx][sy] = false;
}

int main()
{
    cin >> h >> w;
    field.resize(h);

    for (int i = 0; i < h; ++i) cin >> field[i];
    used.assign(h, vector<bool>(w, false));

    dfs(0, 0, 0);

    cout << ans << endl;

}
