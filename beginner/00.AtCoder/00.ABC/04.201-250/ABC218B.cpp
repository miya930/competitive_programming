#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<int> p(26);
    for (int i = 0; i < 26;++i) {
        cin >> p[i];
        p[i]--;
    }

    string s = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; ++i) {
        cout << s[p[i]];
    }
    cout << endl;
}
