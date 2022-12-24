#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s1 = "HDCS";
string s2 = "A23456789TJQK";

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (s[i] == s[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        bool isok1 = false;
        bool isok2 = false;
        for (int j = 0; j  < s1.size(); ++j) {
            if (s[i][0] == s1[j]) isok1 = true;
        }
        for (int j = 0; j < s2.size(); ++j) {
            if (s[i][1] == s2[j]) isok2 = true;
        }
        if (!isok1 || !isok2) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
