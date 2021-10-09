#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
            if (i == s.size()-1) {
                cout<< "No" << endl;
                return 0;
            }
            if (s[i+1] != t[i] || s[i] != t[i+1]) {
                cout << "No" << endl;
                return 0;
            } else {
                swap(s[i], s[i+1]);
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
