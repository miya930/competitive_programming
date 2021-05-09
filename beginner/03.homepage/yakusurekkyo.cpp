#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> enum_devisors(ll N) {
    vector<ll> res;
    for (ll i = 0; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N / i != i) res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll N;
    cin >> N;

    const auto& res = enum_devisors(N);
    for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;

}
