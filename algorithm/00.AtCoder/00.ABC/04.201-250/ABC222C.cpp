/**
   created: 09.10.2021 20:12:48
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

bool my_compare(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }

    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return true;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(2*n);
    for (int i = 0; i < 2*n; ++i) cin >> s[i];

    vector<pair<int, int> > shori(2*n);
    for (int i = 0; i < 2*n; ++i) {
        shori[i] = make_pair(0, i);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2*n-1; j += 2) {
            sort(shori.begin(), shori.end(), my_compare);
            if (s[shori[j].second][i] == 'G' && s[shori[j+1].second][i] == 'C') shori[j].first++;
            else if (s[shori[j].second][i] == 'C' && s[shori[j+1].second][i] == 'G') shori[j+1].first++;
            else if (s[shori[j].second][i] == 'P' && s[shori[j+1].second][i] == 'C') shori[j+1].first++;
            else if (s[shori[j].second][i] == 'C' && s[shori[j+1].second][i] == 'P') shori[j].first++;
            else if (s[shori[j].second][i] == 'G' && s[shori[j+1].second][i] == 'P') shori[j+1].first++;
            else if (s[shori[j].second][i] == 'P' && s[shori[j+1].second][i] == 'G') shori[j].first++;
        }
    }

    sort(shori.begin(), shori.end(), my_compare);
    for (int i = 0; i < 2*n; ++i) cout << shori[i].second + 1 << endl;
    
    return 0;
}
