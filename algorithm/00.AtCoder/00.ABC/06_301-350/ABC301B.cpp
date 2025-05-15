#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{  
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while(1) {
        bool exist = false;
        for (int i = 0; i < a.size()-1; i++) {
            int diff = abs(a[i] - a[i+1]);
            if (diff != 1) {
                exist = true;
                if (a[i] < a[i+1]) {
                    for (int j = 0; j < diff-1; j++) {
                        a.insert(a.begin() + i + 1, a[i] + (diff-1) - j);
                    }
                } else {
                    int tmp = a[i+1];
                    for (int j = 0; j < diff-1; j++) {
                        a.insert(a.begin() + i + 1, tmp + j + 1);
                    }
                }
            }
        }
        if (!exist) break;
    }

    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
