#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    string str = s;
    str.erase(str.size()-1);
    for (int i = 0; i < n-1; ++i) {
        if (str.size()%2 != 0) str.erase(str.size()-1);
        else {
            bool flag = true;
            for (int j = 0; j < (int)str.size()/2; ++j) {
                if (str[j] != str[str.size()/2+j]) flag = false;
            }

            if (flag) {
                cout << (int)str.size() << endl;
                return 0;
            }
            str.erase(str.size()-1);
        }
    }

    cout << (int)str.size() << endl;
    return 0;
}
