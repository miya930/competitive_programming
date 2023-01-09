#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    priority_queue<ll> que1, que2;

    for (int i = 0; i < n; ++i) {
        if (a[i]%2==0) que1.push(a[i]);
        else que2.push(a[i]);
    }

    if (que1.size() <= 1 && que2.size() <= 1) {
        cout << -1 << endl;
        return 0;
    }

    ll sum1 = 0, sum2 = 0;

    if (que1.size() > 1) {
        sum1 = que1.top();
        que1.pop();
        sum1 += que1.top();
    }

    if (que2.size() > 1) {
        sum2 = que2.top();
        que2.pop();
        sum2 += que2.top();
    }

    cout << max(sum1, sum2) << endl;

    return 0;
}
