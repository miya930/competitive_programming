#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n, q;
    string s;
    cin >> n >> s >> q;
    
    bool swap_flag = false;
    for (int i = 0; i < q; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            a--; b--;
            if (swap_flag) {
                if (a < n) a += n;
                else a -= n;
                if (b < n) b += n;
                else b -= n;
                swap (s[a], s[b]);
            }
            else swap(s[a], s[b]);
        }
        if (t == 2) swap_flag = !swap_flag;
    }
    if (swap_flag) cout << s.substr(n, n) + s.substr(0, n) << endl;
    else cout << s << endl;
}
