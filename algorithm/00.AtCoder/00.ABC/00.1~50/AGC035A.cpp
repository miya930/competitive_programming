#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i]; 

    int ans = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        ans = ans ^ a[i];
        if (a[i] == 0) z++; 
    }
    if (ans == 0 && n%2 == 1) cout << "Yes" << endl;
    else if (ans == 0 && z > 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
