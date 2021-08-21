#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    int k;
    cin >> s >> k; k--;
    int n = s.size();
    vector<int> v(n);
    for (int i = 0 ; i < n; ++i) v[i] = i;

    sort(s.begin(), s.end());

    vector<string> ans;
    do {
        string temp = "";
        for (int i = 0 ;i < n; ++i) {
            temp += s[v[i]];
        }
        ans.push_back(temp);
    } while(next_permutation(v.begin(), v.end()));

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    //for (int i = 0 ; i < ans.size(); ++i) cout << "ans[i] = " << ans[i] << endl;

    cout << ans[k] << endl;
    return 0;

}
