#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> forw, back;
    if (s[0] == 'L') back.push_back(0);
    else forw.push_back(0);

    for (int i = 0; i < n-1; ++i) {
        if (s[i] == 'L' && s[i+1] == 'R') {
            forw.push_back(i+1);
        } else if (s[i] == 'L' && s[i+1] =='L') {
            back.push_back(i+1);
        } else if (s[i] == 'R' && s[i+1] == 'L') {
            back.push_back(i+1);
        } else {
            forw.push_back(i+1);
        }
    }

    if (s[n-1] == 'R') forw.push_back(n);
    else back.push_back(n);

    reverse(back.begin(), back.end());
    for (int i = 0; i < back.size(); ++i) {
        forw.push_back(back[i]);
    }

    for (int i = 0; i < forw.size(); ++i) {
        cout << forw[i] << " ";
    }
    cout << endl;

    return 0;
}
