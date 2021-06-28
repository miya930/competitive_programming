#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> t(n), l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> t[i] >> l[i] >> r[i];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        bool l_i = false;
        bool r_i = false;
        if (t[i] == 2) r_i = true;
        else if (t[i] == 3) l_i = true;
        else if (t[i] == 4) {
            r_i = true;
            l_i = true;
        }
        for (int j =i+1; j < n; ++j) {
            bool r_j = false;
            bool l_j = false;
            if (t[j] == 2) r_j = true;
            else if (t[j] == 3) l_j = true;
            else if (t[i] == 4) {
                r_j = true;
                l_j = true;
            }

            bool flag = true;
            if (((l[i] > r[j]) || (l[j] > r[i]))) flag = false;

            if((r_i || l_j) && (r[i] == l[j])) flag = false;
            if((l_i || r_j) && (l[i] == r[j])) flag = false;

            if(flag) ans++;
        } 
    }
    cout << ans << endl;
}
