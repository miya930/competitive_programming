#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
private:
    vector<int> bit;
    int n;

public:
    BIT(int size) {
        n = size;
        bit.resize(n+1);
    }

    void add(int a, int w) {
        for (int x = a; x <= n; x += x & -x) bit[x] += w;
    }

    int sum(int a) {
        int ret = 0;
        for (int x = a; x > 0; x -= x & -x) ret += bit[x];
        return ret;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]++;
    }

    BIT b(n);
    ll inv = 0;
    for (int i = 0; i < n; ++i) {
        inv += i - b.sum(a[i]);
        b.add(a[i], 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << inv << endl;
        inv += n - a[i]*2 + 1;
    }

    return 0;
}
