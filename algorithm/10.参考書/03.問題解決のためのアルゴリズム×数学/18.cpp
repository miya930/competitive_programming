#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> vec(4);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        switch(a[i]){
            case 100:
                vec[0]++;
                break;
            case 200:
                vec[1]++;
                break;
            case 300:
                vec[2]++;
                break;
            case 400:
                vec[3]++;
                break;
            default:
                break;
        }
    }

    ll ans = 0;
    ans += (vec[0]*vec[3]);
    ans += (vec[1]*vec[2]);

    cout << ans << endl;
    return 0;
}
