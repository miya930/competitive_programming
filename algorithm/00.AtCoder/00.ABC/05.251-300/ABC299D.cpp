#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;

bool check(int key) {
    cout << "? " << key+1 << endl;
    cin >> t;

    if (t == 1) return true;
    else return false;

}

int main()
{
    int n;
    cin >> n;
    int left = -1, right = n;
    string s = "";
    for (int i = 0; i < n; i++) {
        if (i == 0) s.push_back('0');
        else if (i == n-1) s.push_back('1');
        else s.push_back('*');
    }

    int ans = 0;
    while(right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid;
        s[mid] = '0' + t;
    }
    
    for (int i = 0; i < n-1; i++) {
        if ((s[i] == '0') && (s[i+1] == '1')) {
            ans = i;
            break;
        }
        if ((s[i] == '1') && (s[i+1] == '0')) {
            ans = i;
            break;
        }
    }

    cout << "! " << ans + 1 << endl;
    return 0;
}
