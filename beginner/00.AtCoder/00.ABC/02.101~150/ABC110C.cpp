#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<bool> > seen(30, vector<bool>(30, false));

int main()
{
    string s, t;
    cin >> s >> t;

    int n = (int)s.size();
    vector<int> vec_in(30, 0), vec_out(30, 0);
    for (int i = 0; i < n; ++i) {
        int s_order = s[i] - 'a';
        int t_order = t[i] - 'a';
        if (seen[s_order][t_order] == false) {
            seen[s_order][t_order] = true;
            vec_out[s_order]++;
            vec_in[t_order]++;
        }
    }
    
    bool ok = true;
    for (int i = 0; i < (int)vec_in.size(); ++i) {
        if (vec_out[i] > 1 || vec_in[i] > 1) ok = false;
    }
    
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}