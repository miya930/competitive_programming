#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 100000;
vector<int> vec;

int calc(int n) {
    int res = 0;
    while (n > 0) {
        res += (n%10);
        n /= 10;
    }
    return res;
}

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> nxt(mod);

    for (int i = 0; i < mod; ++i) {
        nxt[i] = (i + calc(i)) % mod;
    }

    vector<int> vec(mod, -1);
    int pos = n, cnt = 0;
    while (vec[pos] == -1) {
        vec[pos] = cnt;
        pos = nxt[pos];
        cnt++;
    }
    int cycle = cnt - vec[pos];
    if (k >= vec[pos]) k = (k-vec[pos])%cycle + vec[pos];
    
    int answer = -1;
    for (int i = 0; i < mod; ++i) {
        if (vec[i] == k) {
            answer = i;
        }
    }

    cout << answer << endl;
    return 0;

}
