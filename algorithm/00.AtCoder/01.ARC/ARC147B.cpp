#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p;
vector<pair<char,int>> ans;

void f(char c, int i) {
    ans.push_back(make_pair(c, i+1));
    swap(p[i], p[i+1+c-'A']);
}

int main()
{
    int n;
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-2; j++) {
            if (p[j]%2 != p[j+2]%2 && p[j]%2 != j%2) f('B', j);
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (p[i]%2 != p[i+1] && p[i]%2 == i%2) f('A', i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-2; j++) {
            if (p[j] > p[j+2]) f('B', j);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
