#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int> que;
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        que.push(l);
    }

    int ans = 0;
    while (que.size()) {
        int l1, l2;
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();

        ans += l1 + l2;
        que.push(l1+l2);
    }
    
    cout << ans << endl;
}
