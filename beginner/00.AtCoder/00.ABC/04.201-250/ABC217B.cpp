#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    vector<string> s(3);
    for (int i = 0; i < 3; ++i) cin >> s[i];
    map<string, int> mp;
    for (int i = 0; i < 3; ++i) mp[s[i]]++;
    if (mp["ABC"] == 0) cout << "ABC" << endl;
    else if (mp["ARC"] == 0) cout <<  "ARC" << endl;
    else if (mp["AGC"] == 0) cout << "AGC" << endl;
    else if (mp["AHC"] == 0) cout << "AHC" << endl;
    
    return 0;
}
