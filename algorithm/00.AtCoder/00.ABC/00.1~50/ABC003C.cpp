#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<double, vector<double>, greater<double>> que;
    for (int i = 0; i < n; ++i) {
        double inp;
        cin >> inp;
        que.push(inp);
    }

    int tmp = n -k;
    for (int i = 0; i < tmp; ++i) que.pop();

    double ans = 0;
    while(!que.empty()) {
        ans = (ans + que.top()) / 2;
        que.pop();
    }

    printf("%.12f\n", ans);
    return 0;
}
