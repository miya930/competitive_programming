#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

int main()
{
    ll L;
    int Q;
    cin >> L >> Q;
    set<int> st;
    st.insert(0);
    st.insert(L);

    for (int q = 0; q < Q; ++q) {
        int c, x;
        cin >> c >> x;
        if (c == 1) st.insert(x);
        else {
            auto high = st.lower_bound(x);
            cout << *high - *prev(high) << endl;
        }
    }

    return 0;
}