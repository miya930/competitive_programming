#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    set<string> st;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j <= i+5; ++j) {
            st.insert(s.substr(i, j-i));
        }
    }

    auto itr = st.begin();
    for (int i = 0; i < k-1; ++i) itr++;
    cout << *itr << endl;

    return 0;
}
