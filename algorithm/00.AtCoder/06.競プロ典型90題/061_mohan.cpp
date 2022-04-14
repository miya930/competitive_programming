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

/* 2022.4.10 復習 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int Q;
    cin >> Q;

    vector<int> fr, ba;
    for (int q = 0; q < Q; ++q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            fr.push_back(x);
        } else if (t == 2) {
            ba.push_back(x);
        } else {
            if (x <= fr.size()) {
                cout << fr[fr.size() - x] << endl;
            } else {
                x -= fr.size();
                cout << ba[x-1] << endl;
            }
        }
    }

    return 0;
}

