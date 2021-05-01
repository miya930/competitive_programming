#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void rec(int d, ll val, vector<ll> &all) {
    all.push_back(val);

    if ( d == 10) return;

    for (int j = -1; j <= 1; j++) {
        int add = (val % 10) + j;
        if (add >= 0 && add <= 9) rec(d+1, val*10 + add, all);
    }
}

int main(void)
{
    int K;
    cin >> K;
    vector<ll> all;
    for (int i = 1; i < 10; i++) rec(1, i, all);

    sort(all.begin(), all.end());

    cout << all[K-1] << endl;
}
