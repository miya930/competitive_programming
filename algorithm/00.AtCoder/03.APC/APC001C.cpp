#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int left = 0, right = n;
    cout << 0 << flush;
    cout << endl;
    string pre;
    cin >> pre;

    for (int i = 0; i < 20; ++i) {
        int mid = (left+right)/2;
        cout << mid << flush;
        cout << endl;

        string tmp;
        cin >> tmp;

        if (tmp == "Vacant") break;

        bool exist = false;
        if (mid%2 == 0 && tmp != pre) exist = true;
        else if (mid%2 == 1 && tmp == pre) exist = true;

        if (exist) right = mid;
        else left = mid;

    }

    return 0;
}
