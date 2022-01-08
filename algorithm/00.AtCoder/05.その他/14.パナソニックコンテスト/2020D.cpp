#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void dfs(string str, char c) {
    if (str.size() >= n) {
        cout << str << endl;
        return;
    }

    for (char ch = 'a'; ch <= c+1; ch++) {
        char tmp = c;
        if (ch == c+1) tmp = ch;
        dfs(str+ch, tmp);    
    }

}

int main()
{
    string s;
    cin >> n;
    s = "a";
    dfs(s, 'a');
    return 0;
}
