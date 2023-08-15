#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    
    for (int i = 0; i < s.size()-1; i+=2) {
        swap(s[i], s[i+1]);
    }

    cout << s << endl;

    return 0;
}
