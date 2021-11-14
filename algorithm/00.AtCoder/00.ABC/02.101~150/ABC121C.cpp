#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
vector<pair<ll, ll> > drink;

int main()
{
    cin >> n >> m;

    drink.resize(n);
    for (int i = 0 ; i < n; ++i) {
        cin >> drink[i].first >> drink[i].second;
    }

    sort(drink.begin(), drink.end());

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        if (m - drink[i].second > 0){
            ans += (drink[i].first * drink[i].second);
            m -= drink[i].second;
        } else {
            ans += m*drink[i].first;
            break;
        }
    }
    cout << ans << endl;
}
