#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> func(int n) {

    if (n == 1) {
        vector<int> a;
        a.push_back(n);
        return a;
    } 
    
    vector<int> rec = func(n-1), vec;

    int si = rec.size();
    for (int i = 0; i < si; ++i) {
        vec.push_back(rec[i]);    
    }
    vec.push_back(n);
    for (int i = 0; i < si; ++i) {
        vec.push_back(rec[i]);    
    }    

    return vec;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ans = func(n);

    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
