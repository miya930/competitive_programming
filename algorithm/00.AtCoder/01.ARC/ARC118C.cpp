#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> a(3);
    a[0] = 6; a[1] = 10; a[2] = 15;
    set<int> st;
    st.insert(6); st.insert(10); st.insert(15);

    int cnt = 2;
    while (st.size() < n) {
        for (int i = 0; i < 3; ++i) {
            if (st.size() == n) break;
            if (a[i]*cnt <= 10000) st.insert(a[i]*cnt);
        }
        cnt++;
    }


    for (auto x : st) cout << x << " ";
    cout << endl;

    return 0;
}
