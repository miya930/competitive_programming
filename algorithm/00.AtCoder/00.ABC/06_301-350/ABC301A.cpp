#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ta = 0, ao = 0;
    int tcnt = 0, acnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') {
            ta++;
            tcnt = i;
        } else {
            ao++;
            acnt = i;
        }
    }
    if (ta > ao || (ta == ao && tcnt < acnt)) {
        cout << 'T' << endl;
    } else {
        cout << 'A' << endl;
    }

    return 0;
}
