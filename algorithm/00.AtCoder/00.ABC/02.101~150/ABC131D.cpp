#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> pa(n);
    for (int i = 0; i < n; ++i) cin >> pa[i].second >> pa[i].first;
    sort(pa.begin(), pa.end());

    ll now = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i){
        int time = pa[i].second;
        int due = pa[i].first;

        now += time;
        if (now > due) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl; 

    return 0;
}
