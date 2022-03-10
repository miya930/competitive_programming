#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    int Q;
    cin >> S >> Q;

    auto g = [&](char s, ll add) {
        return char('A'+(s-'A'+add)%3);
    };

    std::function<char(ll, ll)> f = [&](ll t, ll k) {
        if (t == 0) return S[k];
        if (k == 0) return g(S[0], t);
        return g(f(t-1, k/2), k%2+1); 
    };

    for (int q = 0; q < Q; ++q) { 
        ll t, k;                 
        cin >> t >> k;

        cout << f(t, k-1) << endl;
    }

    return 0;
}
