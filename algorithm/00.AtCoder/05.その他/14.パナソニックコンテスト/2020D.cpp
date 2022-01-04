#include <bits/stdc++.h>
using namespace std;
int n;
string buf = "";

void dfs(int cu) {
    if (cu == n) {
        cout << buf << endl;
        return;
    }

    char biggest = 'a';
    while(buf.find(biggest) != string::npos) biggest++;
    
    for (char c = 'a'; c <= biggest; c++) {
        buf.push_back(c);
        dfs(cu + 1);
        buf.pop_back();
    }
}

int main()
{
    cin >> n;

    dfs(0);
    return 0;
}
