#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

void output(vector<int> &a){
    cout << a.size();
    for (auto &x : a)
        cout << ' ' << nx;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<int> > bk(200, vector<int>(0));

    int cnt = min(n, 8);

    for (int i = 1; i < (1<<n); ++i) {
        int sig = 0;
        vector<int> s;
        for (int j = 0;j < n; ++j) {
            if(i&(1<<j)) {
                s.push_back(j+1);
                sig += a[j];sig%=200;
            }
        }
        if(bk[sig].size() != 0) {
            cout << "Yes" << endl;
            output(bk[sig]);
            output(s);
            return 0;
        }else {
            bk[sig]=s;
        }
    }
    cout << "No" << endl;
    return 0;
}
