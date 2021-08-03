#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char, long long> mp;
    stack<long long> st;

    long long temp = 0;
    long long acum = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            if (temp > 0) {
                temp *= 10;
                temp += (s[i]-'0');
            } else {
                temp = (s[i]-'0');
            }
        } else if (s[i] == '(') {
            acum *= temp;
            st.push(temp);
            temp = 0;
        } else if (s[i] == ')') {
            temp = st.top();
            acum /= temp;
            st.pop();
            temp = 0;
        } else if (s[i] >= 'a' || s[i] <= 'z') {
            if (temp != 0) {
                mp[s[i]] += temp*acum;
                temp = 0;
            } else {
                mp[s[i]] += acum;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        cout << (char)('a' + i) << " " << mp['a'+i] << endl;
    }
    return 0;
}
