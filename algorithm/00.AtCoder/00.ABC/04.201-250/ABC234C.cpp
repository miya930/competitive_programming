#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string tobin(ll k) {
    string res = "";
    while (k > 0) {
        int tmp = k%2;
        k /= 2;
        res.push_back(tmp+'0');
    }
    return res;
}

int main()
{
    ll k;
    cin >> k;

    string ans = tobin(k);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == '1') cout << '2';
        else cout << '0';
    }
    cout << endl;

    return 0;
}
