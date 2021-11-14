#include <bits/stdc++.h>

using namespace std;
using ll = long long;   

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    vector<int> vec;
    int cnt = 1;
    for (int i = 1 ; i< n; ++i) {
        if (s[i] != s[i-1]) {
            if (s[i-1] == '1') vec.push_back(cnt);
            else {
                vec.push_back(-cnt);
            } 
            cnt = 1;
        } else {
            cnt++;
        }
    }

    if (s[n-1] == '1') vec.push_back(cnt);
    else {
        vec.push_back(-cnt);
    }

    queue<int> que;
    int sum = 0;
    int sz = vec.size();
    int ans = 0;
    cnt = 0;
    for (int i = 0; i < sz; ++i) {
        int add = vec[i];
        que.push(add);
        sum += abs(add);

        if (add < 0) {
            cnt++;
            if (cnt > k) {
                int del = que.front();
                que.pop();
                sum -= abs(del);
                if (del > 0) {
                    int del2 = que.front();
                    que.pop();
                    sum -= abs(del2);
                }
            }
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
