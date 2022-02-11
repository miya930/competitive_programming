#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<bool> isprime(100000, true);
    isprime[0] = false; isprime[1] = false;

    for (int i = 2; i < 100000; ++i) {
        if (isprime[i] == false) continue;
        for (int j = i*2; j < 100000; j += i) {
            isprime[j] = false;
        }
    }

    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < 100000; ++i) {
        if (i%5==1 && isprime[i] == true) {
            ans.push_back(i);
            cnt++;
        }
        if (cnt == n) break;
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
