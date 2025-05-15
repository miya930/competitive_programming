#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    for (int i = 0; i <= k; i++) { //左からi個
        for (int j = 0; j <= k; j++) { //右からj個
            if (i+j > k || i+j > n) continue;
            
            priority_queue<int, vector<int>, greater<int>> que;

            for (int l = 0; l < i; l++) que.push(v[l]);
            for (int l = n-1; l > n-1-j; l--) que.push(v[l]);
            int res = k - (i + j);
            for (int l = 0; l < res; l++) {
                if (!que.empty() && que.top() < 0) que.pop();
            }
            int sum = 0;
            while(!que.empty()) {
                sum += que.top();
                que.pop();
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
