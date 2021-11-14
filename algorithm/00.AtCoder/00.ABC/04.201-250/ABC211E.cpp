#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<string> vs;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, k;
int ans;

void dfs(vs s) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'o') cnt++;
        }
    }
    if (cnt==k) {
        ++ans;
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] != '.') continue;
            if (cnt != 0) {
                bool ok = false;
                for (int v = 0; v < 4; ++v) {
                    int nx = i + dx[v], ny = j + dy[v];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (s[nx][ny] == 'o') ok = true;
                }
                if (!ok) continue;
            }
            s[i][j] = 'o';
            dfs(s);
            s[i][j] = '#';
            dfs(s);
            return;
        }
    }
}

int main()
{
    cin >> n >> k;
    vs s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    dfs(s);
    cout << ans << endl;
    return 0;
}
