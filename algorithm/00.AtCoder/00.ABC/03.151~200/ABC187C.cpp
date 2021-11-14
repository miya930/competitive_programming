#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    map<string, int> mp;
    for (int i = 0; i < n; ++i) mp[s[i]]++;

    for (int i = 0 ;i < n; ++i) {
        string tmp = '!' + s[i];
        if (mp[tmp]) {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
    return 0;
}
