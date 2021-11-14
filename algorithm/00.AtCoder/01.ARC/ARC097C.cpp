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

    set<string> st;
    int n = s.size();

    int cnt = 0;
    string last = "";
    for (int i = 0; i < n; ++i) {
        string str = "";
        for (int j = i; j < n; ++j) {
            str = str + s[j]
            ;
            if (cnt < k) {
                cnt++;
                st.insert(str);
                last = max(last, str);
            } else {
                if (last > str) {
                    auto it = st.begin();
                    for (int i = 0; i < k-1; ++i) it++;
                    st.insert(str);
                    last = *(it);
                }
            }
        }
    }

    auto itr = st.begin();
    for (int i = 0; i < k-1; ++i) itr++;
    cout << *itr << endl;

    return 0;
}


/***************************
 * 以下、ユーザー解答参考にした。
 **************************/

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
