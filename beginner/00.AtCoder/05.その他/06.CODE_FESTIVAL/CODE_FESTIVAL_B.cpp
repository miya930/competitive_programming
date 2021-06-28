#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];
    
    cin >> m;
    vector<int> t(m);
    for (int i = 0; i < m; ++i) cin >> t[i];

    map<int, int> md, mt;
    for (int i = 0; i < n; ++i) md[d[i]]++;
    for (int i = 0; i < m; ++i) mt[t[i]]++;

    for (auto x: mt) {
        if (md[x.first] < mt[x.first]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
