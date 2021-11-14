#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> a;
    for (int i = 0; i < n; ++i) {
        int b; cin >> b;
        a.push(b);
    }

    for (int i = 0; i < m; ++i) {
        int x = a.top();
        a.pop();
        a.push(x/2);
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a.top();
        a.pop();
    }
    cout << ans << endl;
}
