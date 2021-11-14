#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int Q;
    cin >> Q;
    priority_queue<int, vector<int>, greater<int> > que;
    vector<int> vec;
    int pre = 0, now = 0;

    for (int q = 0; q < Q; ++q) {
        int c;
        cin >> c;
        if (c == 1) {
            int x; cin >> x;
            vec.push_back(x);
            now++;
        } else if (c == 2) {
            if (que.empty()) {
                cout << vec[pre] << endl;
                pre++;
            } else {
                cout << que.top() << endl;
                que.pop();
            }

        } else {
            for (int i = pre; i < now; ++i) que.push(vec[i]);
            pre = now;
        }
    }
    return 0;
}
