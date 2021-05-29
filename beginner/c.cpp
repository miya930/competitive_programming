#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;
        vector<int> p(m);
        for (int i = 0; i < m; ++i) cin >> p[i];
        int cnt = 1;
        bool odd_flag, even_flag;
        vector<int> a;
        while(1) {
            if (cnt%2 == 0) {
                for (int i = 0; i < m; i += 2) {
                    if (p[i]+1 > i) {
                        swap(p[i],p[i+1]);
                        a.push_back(i);
                        break;
                    }
                    if ()
                }
            } else {
                for (int i = 1; i < m; i += 2) {
                    if (p[i]+1 > i) {
                        swap(p[i], p[i+1]);
                        a.push_back(i);
                        break;
                    }
                }
            }

            cnt++;
        }
    }
}
