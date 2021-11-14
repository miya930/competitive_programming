#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<int, int> mp;
    for (int i = 0; i < (int)s.size(); ++i) mp[s[i] - '0']++;

    if (s.size() < 3) {
        int num = stoi(s);
        if (num % 8 == 0) {
            cout << "Yes" << endl;
            return 0;
        }
        if (s.size() == 2) {
            int t = (s[1]-'0')*10 + s[0]-'0';
            if (t % 8 == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    for (int i = 104; i < 1000; i += 8) {
        map<int, int> a;

        int b = i;
        for (int j = 0; j < 3; j++) {
            a[b % 10]++;
            b /= 10;
        }
        int cnt = 0;
        for (int k = 1; k < 10; ++k) {
            if (a[k] != 0) {
                if (mp[k] >= a[k]) {
                    switch (a[k]) {
                    case 1:
                        cnt++;
                        break;
                    case 2:
                        cnt += 2;
                        break;
                    case 3 :
                        cnt += 3;
                        break;
                    }
                }
            }
        }
        if (cnt == 3) {
            cout << "Yes" << endl;
            return 0;
        } 
    }
    cout << "No" << endl;
    return 0;
}
