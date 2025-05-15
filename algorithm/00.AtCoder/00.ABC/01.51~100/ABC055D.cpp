#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, char> rev;
    rev['S'] = 'W';
    rev['W'] = 'S';

    string ans;
    for (int sss = 0; sss < 2; sss++) {
        string form = "";
        if (sss == 0) {
            form += "S";
        } else {
            form += "W";
        }
        string str = form;
        for (int ttt = 0; ttt < 2; ttt++) {
            if (ttt == 0) {
                str += "S";
            } else {
                str += "W";
            }
            for (int i = 2; i < n; i++) {
                if (str[i-1] == 'W') {
                    if (s[i-1] == 'o') {
                        str += rev[str[i-2]];
                    } else {
                        str += str[i-2];
                    }
                } else {
                    if (s[i-1] == 'x') {
                        str += rev[str[i-2]];
                    } else {
                        str += str[i-2];
                    }                    
                }
            }

            bool ng = false;
            for (int i = 0; i < n; i++) {
                if (str[i] == 'S') {
                    if (s[i] == 'o') {
                        if (str[(i-1+n)%n] != str[(i+1)%n]) {
                            ng = true;
                        }
                    } else {
                        if (str[(i-1+n)%n] == str[(i+1)%n]) {
                            ng = true;
                        }
                    }
                } else {
                    if (s[i] == 'x') {
                        if (str[(i-1+n)%n] != str[(i+1)%n]) {
                            ng = true;
                        }
                    } else {
                        if (str[(i-1+n)%n] == str[(i+1)%n]) {
                            ng = true;
                        }
                    }                    
                }
            }

            if (!ng) {
                cout << str << endl;
                return 0;
            }

            str = form;
        }
    }
    cout << -1 << endl;
    return 0;
}
