#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    long long n, l, p;
    cin >> n >> l >> p;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    priority_queue<long long> que;

    long long cur = p;
    int ans = 0;
    long long pos = 0;
    
    for (int i = 0; i < n ;++i) {
        long long d = a[i] - pos;

        while (cur - d < 0) {
            if (!que.empty()){
                cout << -1 << endl;
                return 0;
            }
            cur += que.top();
            que.pop();
            ans++;
        }

        cur -= d;
        pos = a[i];
        que.push(b[i]);
    }
    cout << ans << endl;
    return 0;
}
