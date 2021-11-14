#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    vector<int> order(n);
    rep(i, n) order[i] = i;

    int a = 0, res_a = 0;
    int b = 0, res_b = 0;
    do {
        a++; b++;
        int match_p = 0, match_q = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == order[i]+1) match_p++;
            if (q[i] == order[i]+1) match_q++;
        }
        if (match_p == n) res_a = a;
        if (match_q == n) res_b = b;
    } while(next_permutation(order.begin(), order.end()));
    
    cout << abs(res_a-res_b) << endl;
}
