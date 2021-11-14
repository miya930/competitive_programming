#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> a(200100);

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> s(n), t(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i] >> p[i];
        a[s[i]] += p[i];
        a[t[i]] -= p[i]; 
    }
    
    bool over = false;
    for (int i = 0; i < a.size(); ++i) {
        a[i+1] += a[i];
        if (a[i] > w) over = true;
    }
    
    if (over) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
