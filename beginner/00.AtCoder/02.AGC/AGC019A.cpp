#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    vector<long long> a(4);
    long long n;
    for (int i = 0; i < 4; ++i) cin >> a[i];
    cin >> n;

    vector<tuple<int, double, int> > tpl(4);

    double qy = 0.25;
    for (int i = 0; i < 4; ++i) {
        get<0>(tpl[i]) = (2 / qy) * a[i];
        get<1>(tpl[i]) = qy;
        get<2>(tpl[i]) = a[i];
        qy *= 2;
    }

    sort(tpl.begin(), tpl.end());

    long long ans = 0;
    for (int i = 0; i < 4; ++i) {
        double quantity = get<1>(tpl[i]);
        int cost = get<2>(tpl[i]);

        if (n < quantity) continue;
       
        ans += (cost * (long long)(n/quantity));
        n = n - (long long)(n / quantity) * quantity;
        if (n == 0) break;
    }
    cout << ans << endl;
}
