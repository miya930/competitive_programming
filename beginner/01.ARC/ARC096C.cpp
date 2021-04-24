#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;

    if ((A+B) < 2*C){            // A + B < 2CならAピザ, Bピサをそれぞれ購入したほうが安い
        cout << A*X + B*Y << endl;
    } else {                      // A + B > 2Cの場合、
        if (X < Y){             // X < Y なら2C枚 ABピザを買う。
            ans += 2*C * X;
            if (B > 2*C)        // B > 2+Cの場合、ABピザを買ったほうが安い
                ans += 2*C*(Y-X);
            else
                ans += B*(Y-X);
        } else {
            ans += 2*C * Y;
            if (A > 2*C)
                ans += 2*C*(Y-X);
            else
                ans += A*(X-Y);
        }
        cout << ans << endl;
    }
}
