#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n >> Q;
    string s;
    cin >> s;

    int sft = 0;
    for (int q = 0; q < Q; ++q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            sft += x;
            sft %= s.size();
        } else {
            x--;
            cout << s[(x-sft+s.size())%s.size()] << endl;
        }
    }

    return 0;
}
