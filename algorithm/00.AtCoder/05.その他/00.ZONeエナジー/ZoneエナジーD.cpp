#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    deque<char> t;
    bool parity = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') parity = !parity;
        else {
            if (parity) {
                if (!t.empty() && t.back() == s[i]) t.pop_back();
                else t.push_back(s[i]);
            } else {
                if (!t.empty() && t.front() == s[i]) t.pop_front();
                else t.push_front(s[i]);
            }
        }
    }
    int tn = t.size();
    if (parity) {
        for (int i = 0; i < tn; ++i) {
            cout << t.front();
            t.pop_front();
        }
    } else {
        for (int i = 0; i < tn; ++i) {
            cout << t.back();
            t.pop_back();
        }
    }
    cout << endl;

    return 0;
}
