#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    string s;
    cin >> n >> x >> s;

    map<ll,ll> ignore;
    queue<ll> que;
    ll ucnt = 0;
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == 'U') {
            ucnt++;
            que.push(i);
        } else {
            if (ucnt > 0) {
                ucnt--;
                ignore[i] = 1;
                ignore[que.front()] = 1;
                que.pop();
            }
        }
    }

    string str = "";
    for (int i = 0; i < n; ++i) {
        if (ignore[i] == 0) str += s[i];
    }

    ll ans = x;
    for (auto y : str) {
        if (y == 'L') ans = ans*2;
        else if (y == 'R') ans = ans*2 + 1;
        else if (y == 'U') ans /= 2;
    }
    
    cout << ans << endl;

    return 0;
}




/******* stackを使った解き方 ************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    string s;
    cin >> n >> x >> s;

    stack<char> st;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') st.push(s[i]);
        else if (s[i] == 'R') st.push(s[i]);
        else {
            if (st.empty() || st.top() == 'U') st.push(s[i]);
            else st.pop();
        }
    }
    string str = "";
    while(!st.empty()) {
        char y = st.top(); st.pop();
        str = y + str;
    }

    for (auto y : str) {
        if (y == 'U') x /= 2;
        else if (y == 'L') x *= 2;
        else x = x*2 + 1;
    }

    cout << x << endl;
    return 0;
}
