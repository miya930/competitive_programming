#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> x(5*n);
    for (int i = 0; i < 5*n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    ll sum = 0;
    for (int i = n; i < 4*n; i++) {
        sum += x[i];
    }

    printf("%.10f\n", (double)sum / (double)3 / (double)n);
    return 0;
}
