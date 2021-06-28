#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    vector<string> vec;
    bool flag = false;
    for (int i = 0 ; i < s.size()-t.size()+1; ++i) {
        bool ok = true;
        for (int j = 0; j < t.size(); ++j) {
            if ((s[i+j] != '?') && (t[j] != s[i+j])) ok = false;
        }
        

        if (ok) {
            string s_c = s;
            for (int k = 0; k < t.size(); ++k) s_c[i+k] = t[k];
            for (int l = 0; l < s.size(); ++l) {
                if (s_c[l] == '?') s_c[l] = 'a';
            }
            flag = true;
            vec.push_back(s_c);
        }
    }

    if (!flag) cout << "UNRESTORABLE" << endl;
    else cout << vec[vec.size()-1] << endl;
    
    return 0;
}
