#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > a, b, c;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b.push(x);
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        c.push(x);
    }

    int aa, bb, cc;
    int ans = 0;
    while(!a.empty()) {
        aa = a.top(); a.pop();

        while(!b.empty() && b.top() <= aa) b.pop();
        if (b.empty()) break;
        bb = b.top(); b.pop();

        while(!c.empty() && c.top() <= bb) c.pop();
        if (c.empty()) break;
        cc = c.top(); c.pop();    
        
        ans++;
    }
    cout << ans << endl;
    return 0;
}
