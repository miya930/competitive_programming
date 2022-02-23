#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string uns = "UNSOLVABLE";
vector<char> used, chars;
const int n = 3;
vector<string> str(n);

bool check() {
    map<char, char> mapping;
    for (int i = 0; i < 10; ++i) {
        if (used[i] != 0) {
            mapping[used[i]] = char('0' + i);
        }
    }
    
    vector<string> s(n, "");
    for (int i = 0; i < n; ++i) {
        for (auto c : str[i]) s[i] += mapping[c];
    }

    for (int i = 0; i < n; ++i) {
        if (to_string(stoll(s[i])) != s[i]) return false;
    }

    if ((stoll(s[0]) + stoll(s[1])) != stoll(s[2])) return false;

    for (int i = 0; i < n; ++i) {
        if (stoll(s[i]) == 0) return false;
    }

    for (int i = 0; i < n; ++i) cout << s[i] << endl;
    return true;
}

bool dfs(int x) {
    if (x == chars.size()) return check();

    for (int i = 0; i < 10; ++i) {
        if (used[i] != 0) continue;

        used[i] = chars[x];
        if (dfs(x+1)) return true;
        used[i] = 0; 
    }

    return false;
}

int main()
{
    used.assign(30, 0);
    for (int i = 0; i < n; ++i) cin >> str[i];

    for (int i = 0; i < n; ++i) {
        for (auto x : str[i]) {
            chars.push_back(x);
        }
    }
    sort(chars.begin(), chars.end());
    chars.erase(unique(chars.begin(), chars.end()), chars.end());

    if (chars.size() > 10) {
        cout << uns << endl;
        return 0;
    }

    bool res = dfs(0);
    if (!res) cout << uns << endl;

    return 0;
}
