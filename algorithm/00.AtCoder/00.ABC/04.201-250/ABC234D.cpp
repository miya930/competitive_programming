#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n), copy(k);
    for (int i = 0; i < n; ++i) cin >> p[i];

    for (int i = 0; i < k; ++i) copy[i] = p[i];
    sort(copy.rbegin(), copy.rend());

    int now = copy[k-1];
    cout << now << endl;
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < k-1; ++i) que.push(copy[i]);

    for (int i = k; i < n; ++i) {
        if (now < p[i]) {
            que.push(p[i]);
            now = que.top();
            que.pop();
        }
        cout << now << endl;
    }

    return 0;
}
