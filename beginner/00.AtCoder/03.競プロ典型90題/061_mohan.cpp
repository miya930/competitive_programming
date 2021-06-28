#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int q;
    cin >> q;
    vector<int> t(q+1), x(q+1);
    for (int i = 1; i <= q; ++i) cin >> t[i] >> x[i];

    deque<int> deq;
    for (int i = 1; i <= q; ++i) {
        if (t[i] == 1) deq.push_front(x[i]);
        else if (t[i] == 2) deq.push_back(x[i]);
        else cout << deq[x[i]-1] << endl;
    }
    return 0;
}
