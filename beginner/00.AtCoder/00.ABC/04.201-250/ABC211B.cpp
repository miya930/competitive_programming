#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    vector<string> s(4);
    for (int i = 0; i < 4; ++i) cin >> s[i];

    vector<bool> vec(4);
    for (int i = 0; i < 4; ++i) {
        if (s[i] == "H") vec[0] = true;
        else if (s[i] == "2B") vec[1] = true;
        else if (s[i] == "3B") vec[2] = true;
        else if (s[i] == "HR") vec[3] = true;
    }

    if (vec[0] & vec[1] & vec[2] & vec[3]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
