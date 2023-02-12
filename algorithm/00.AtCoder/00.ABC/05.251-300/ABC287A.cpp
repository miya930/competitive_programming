#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{   
    int n;
    cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "For") cnt++;
    }

    if (cnt >= (n+1)/2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
