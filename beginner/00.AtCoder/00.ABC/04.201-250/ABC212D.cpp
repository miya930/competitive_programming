#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;\

int main()
{
    int Q;
    cin >> Q;

    priority_queue<long long, vector<long long>, greater<long long> > que;

    long long sum = 0;
    for (int q = 0; q < Q; ++q) {
        long long p;
        cin >> p;

        if (p==1) {
            long long x;
            cin >> x;
            que.push(x-sum);
        } else if (p==2) {
            long long x;
            cin >> x;
            sum += x;
        } else {
            cout << que.top() + sum << endl;
            que.pop();
        }
    }
    return 0;
}
