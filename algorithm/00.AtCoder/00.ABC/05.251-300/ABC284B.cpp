#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        map<int,int> mp;
        for (int i = 0; i < n; i++) {
            if (a[i]%2==0) mp[0]++;
            else mp[1]++;
        }

        cout << mp[1] << endl;
    }

    return 0;
}
