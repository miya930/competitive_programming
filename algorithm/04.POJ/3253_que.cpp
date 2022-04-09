#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) cin >> l[i];

    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; ++i) que.push(l[i]);

    ll ans = 0;
    while(que.size() > 1) {
        int t1 = que.top(); que.pop();
        int t2 = que.top(); que.pop();

        ans += (t1+t2);
        que.push(t1+t2);
    }

    cout << ans << endl;
    return 0;
}
