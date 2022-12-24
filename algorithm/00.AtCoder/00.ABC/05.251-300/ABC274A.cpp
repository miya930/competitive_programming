#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;

    string s = "";
    int dig = 1;
    for (int i = 0; i < 5; ++i) {
        if (i == 1) s.push_back('.');
        else {
            s.push_back((((b*dig)/a)%10 + '0'));
            dig *= 10;

            if (i == 4) {
                int tmp = (b*dig/a)%10;
                if (tmp >= 5) {
                    s[i] = (s[i]+1);
                }
            }
        }
    }

    cout << s << endl;

    return 0;
}

/* 普通の方法 */
int main()
{
    double a, b;
    cin >> a >> b;

    printf("%.3f\n", b/a);

    return 0;
}

