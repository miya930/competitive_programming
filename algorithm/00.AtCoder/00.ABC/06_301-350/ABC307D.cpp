#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<int> que;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        que.push(s[i]);
        if (s[i] != ')') {
            if (s[i] == '(') cnt++;
        } else if (s[i] == ')') {
            if (cnt > 0) {
                
                while(1) {
                    if (que.top() == '(') {
                        que.pop();
                        break;
                    }
                    que.pop();
                }
                cnt--;
            }
        }
    }

    string ans = "";
    while(!que.empty()) {
        ans += que.top();
        que.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
    return 0;
}
