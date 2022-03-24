#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main()
{
    int n;
    string t;
    cin >> n >> t;

    pair<int,int> ans;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == 'S') {
            ans.first += dx[cnt];
            ans.second += dy[cnt];
        } else {
            cnt++;
            cnt %= 4;
        }
    }

    cout << ans.first << " " << ans.second << endl;
    return 0;
}
