#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool comp(pair<pair<string,int>,int> a, pair<pair<string,int>,int> b) {
    if (a.first.first < b.first.first) return true;
    else if (a.first.first > b.first.first) return false;

    if (a.first.second > b.first.second) return true;
    else return false;
    
}

int main()
{
    int n;
    cin >> n;
    vector<pair<pair<string,int>,int>> pa(n);
    for (int i = 0; i < n; ++i) {
        cin >> pa[i].first.first >> pa[i].first.second;
        pa[i].second = i;
    }

    sort(pa.begin(), pa.end(), comp);

    for (int i = 0; i < n; ++i) cout << pa[i].second+1 << endl;

    return 0;
}
