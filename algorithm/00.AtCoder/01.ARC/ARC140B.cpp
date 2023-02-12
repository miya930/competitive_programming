#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> a;
    deque<int> dq;
    int acnt = 0, ccnt = 0;
    int phase = 0;

    for (int i = 0; i < n; i++) {
        if (phase == 0) {
            if (s[i] == 'A') {
                acnt++;
            } else if (acnt > 0 && s[i] == 'R') {
                phase = 1;
            } else {
                acnt = 0;
            }
        } else if (phase == 1) {
            if (s[i] == 'C') {
                ccnt++;
            } else {

                if (ccnt != 0) {
                    a.push_back(min(acnt, ccnt));
                }

                phase = 0;
                acnt = 0;
                ccnt = 0;

                if (s[i] == 'A') acnt++;
            }

            if (ccnt != 0 && i == n-1) {
                a.push_back(min(acnt, ccnt));
                phase = 0;
                acnt = 0;
                ccnt = 0;
            }
        }
    }

    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = 0; i < a.size(); i++) {
        dq.push_back(a[i]);
        sum += a[i];
    }

    int ans = 0;
    int cnt = 1;
    while(1) {
        if (dq.size() == 0) break;
        if (cnt%2 == 0) {
            dq.pop_front();
        } else {
            int tmp = dq.back();
            dq.pop_back();
            if (tmp > 1) {
                dq.push_back(tmp-1);
            }
        }
        ans++;
    }

    cout << min(2*(ll)a.size(), sum) << endl;
    return 0;
}
