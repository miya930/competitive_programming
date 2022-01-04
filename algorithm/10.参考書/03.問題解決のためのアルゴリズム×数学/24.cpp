#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) cin >> p[i] >> q[i];

    double sum = 0;
    for (int i = 0; i < n; ++i) sum += 1.0*q[i]/p[i];

    printf("%.10f\n", sum);
    return 0;
}
