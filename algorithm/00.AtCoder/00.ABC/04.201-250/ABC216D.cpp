#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_M = 201010;

int n, m;
vector<vector<int> > mem(MAX_M);
vector<queue<int> > a(MAX_M);

int main()
{
    cin >> n >> m;
    queue<int> que;

    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        for (int j = 0; j < k; ++j) {
            int t; cin >> t;
            t--;
            a[i].push(t);
        }
        mem[a[i].front()].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        if (mem[i].size() == 2) {
            que.push(i);
        }
    }

    while(!que.empty()) {
        int now = que.front(); que.pop();

        for (auto x : mem[now]) {
            a[x].pop();
            if (!a[x].empty()) {
                mem[a[x].front()].push_back(x);
                if (mem[a[x].front()].size() == 2) {
                    que.push(a[x].front());
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (a[i].size()) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}
