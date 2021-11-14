#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> s(n), t(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> t[i];

    vector<ll> vec = t;
    for (int i = 0; i < 2*n; ++i) {
        vec[(i+1)%n] = min(vec[(i+1)%n], vec[i%n]+s[i%n]);
    }
    for (int i = 0; i < n; ++i) cout << vec[i] << endl;
    return 0;

}
