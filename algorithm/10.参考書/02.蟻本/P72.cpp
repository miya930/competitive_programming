#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int> que;

    que.push(3);
    que.push(5);
    que.push(1);

    while(!que.empty()) {
        cout << que.top() << endl;
        que.pop();
    }
    return 0;
}
