#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n-8; i++) {
        for (int j = 0; j < m-8; j++) {
            bool ng = false;
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    int ny = i + y;
                    int nx = j + x;
                    if (s[ny][nx] != '#') ng = true;

                    ny = i + 6 + y;
                    nx = j + 6 + x;
                    if (s[ny][nx] != '#') ng = true;
                }
            }
            for (int y = 0; y < 4; y++) {
                int ny = i + y;
                int nx = j + 3;
                if (s[ny][nx] != '.') ng = true;
            }
            for (int x = 0; x < 4; x++) {
                int ny = i + 3;
                int nx = j + x;
                if (s[ny][nx] != '.') ng = true;
            }
            
            if (!ng) ans.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;

    return 0;
}
