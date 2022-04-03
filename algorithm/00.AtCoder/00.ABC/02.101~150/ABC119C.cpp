#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int ans = inf;
int flag[8];
int n, A, B, C;
vector<int> l;

void dfs(int v) {
    if (v == n) {
        int a = 0, b = 0, c = 0;
        int ca = 0, cb = 0, cc = 0;
        for (int i = 0; i < n; ++i) {
            if (flag[i] == 0) {
                a += l[i];
                ca++;
            } else if (flag[i] == 1)  {
                b += l[i];
                cb++;
            } else if (flag[i] == 2) {
                c += l[i];
                cc++;
            }
        }
        if (ca == 0 || cb == 0 || cc == 0) return;
        int tmp = 10*(ca-1) + 10*(cb-1) + 10*(cc-1);
        tmp += abs(A-a) + abs(B-b) + abs(C-c);
        ans = min(ans, tmp);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        flag[v] = i;
        dfs(v+1);
    }
}

int main()
{
    cin >> n >> A >> B >> C;

    l.resize(n);
    for (int i = 0; i < n; ++i) cin >> l[i];

    dfs(0);
    cout << ans << endl;

    return 0;
}
