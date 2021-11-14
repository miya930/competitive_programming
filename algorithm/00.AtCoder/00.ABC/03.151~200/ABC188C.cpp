#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<pair<long long, long long> > a(1<<(n-1)), b(1<<(n-1));
    for (long long i = 0; i < (1<<(n-1)); ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    for (long long i = 0; i < 1<<(n-1); ++i) {
        cin >> b[i].first;
        b[i].second = i + (1<<(n-1)) + 1;
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    if (a[0].first > b[0].first) cout << b[0].second  << endl;
    else cout << a[0].second << endl;
}
