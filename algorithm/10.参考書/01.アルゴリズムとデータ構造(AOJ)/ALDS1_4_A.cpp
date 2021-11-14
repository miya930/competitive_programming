#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, q;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];

    cin >> q;
    vector<int> T(q);
    for (int i = 0; i < q; i++)
        cin >> T[i];

    int cnt = 0;
    bool exist;
    for (int i = 0; i < n; i++) {
        exist = false;
        for (int j = 0; j < q; j++) {
            if (S[i] == T[j])
                exist = true;
        }
        if (exist) cnt++;
    }

    cout << cnt << endl;
}