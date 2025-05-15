#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n >> Q;

    vector<multiset<int>> vec(n);
    vector<set<int>> num(300000);
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            j--;

            vec[j].insert(i);
            num[i].insert(j+1);

        } else if (t == 2) {
            int i;
            cin >> i;
            i--;
            
            for (auto itr = vec[i].begin(); itr != vec[i].end(); itr++) {
                cout << *itr << " ";
            }
            cout << endl;

        } else {
            int i;
            cin >> i;

            for (auto itr = num[i].begin(); itr != num[i].end(); itr++) {
                cout << *itr << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
