#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool check(int mid, string s, int &count) {
    if ((int)s.size() < mid) return false;

    for (int i = 0; i < (int)s.size() - mid + 1; ++i) {
        if (s[i]=='F') continue;
        cout << "i = " << i << "   sc = " << s << "   mid = " << mid <<  endl;

        for (int j = 0; j < mid; ++j) {
            if (s[i+j] == 'F') s[i+j] = 'B';
            else s[i+j] = 'F'; 
        }
        count++;
    }

    bool res = true;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'B') res = false;
    }
    return res;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    vector<pair<int, int> > ans;

    int right = 5100;
    int left = 0;
    while(right - left > 1) {
        string sc = s;
        int count = 0;
        int mid = (right + left) / 2;

        if(check(mid, sc, count)) {
            left = mid;
            ans.push_back(make_pair(count, mid));
        } else {
            right = mid;
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0].first << endl;
    cout << ans[1].second << endl;
}
