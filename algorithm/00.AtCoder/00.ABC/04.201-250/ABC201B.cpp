#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, string> > s(n);
    for (int i = 0; i < n; ++i) cin >> s[i].second >> s[i].first;

    sort(s.rbegin(), s.rend());

    cout << s[1].second << endl;
}
