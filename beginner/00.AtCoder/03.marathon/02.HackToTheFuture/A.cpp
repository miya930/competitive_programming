/**
   created: 10.10.2021 13:29:03
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    // input
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> I(k), J(k), N(b), M(b), C(b);
    for (int i = 0; i < k; ++i) cin >> I[i] >> J[i];

    vector<vector<string> > poly(b);
    for (int i = 0; i < b; ++i) {
        cin >> N[i] >> M[i] >> C[i];

        for (int j = 0; j < N[i]; ++j) {
            string str;
            cin >> str;
        }
    }

    
    // output
    cout << n*n << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           cout << 1 << " " << i << " " << j << endl;
        }
    }




    return 0;
}
