#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,m;

void func(int x, int cnt, vector<int> vec) {
    if (cnt == n) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = x+1; i <= m; i++) {
        vector<int> b  = vec;
        b.push_back(i);
        func(i, cnt+1, b);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        vector<int> a;
        a.push_back(i);
        func(i, 1, a);
    }

    return 0;
}
