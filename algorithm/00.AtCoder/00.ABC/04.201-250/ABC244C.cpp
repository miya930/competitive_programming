#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> vec(3000);
    while(1) {
        
        /* output */
        int rep = 0;
        for (int i = 1; i <= 2*n+1; ++i) {
            if (vec[i] == 0) {
                rep = i;
                vec[i] = 1;
                break;
            }
        }

        cout << rep << endl;
        cout << flush;

        /* input */
        int in;
        cin >> in;

        if (in == 0) break;
        vec[in] = 1;
    }    

    return 0;
}
