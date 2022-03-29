#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<int, vector<int>, greater<int>> que;

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> s(n, vector<char>(n));
    que.push(0); que.push(1); que.push(2);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> que2;
        for (int j = 0; j < n; ++j) {
            if (cnt < 3 && j == que.top()) {
                int v = que.top(); que.pop();
                s[i][v] = '#';
                que2.push((v+3)%n);
                cnt++;
            } else {
                s[i][j] = '.';
            }
        }
        que = que2;
    }

    if (n%3 != 0) {
        for (int i = 0; i < n; ++i) swap(s[0][i], s[n/3-1][i]);
        for (int i = 0; i < n; ++i) swap(s[n-n/3][i], s[n-1][i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}
