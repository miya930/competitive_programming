#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 0;

    if ((A+B) < 2*C){            // A + B < 2C�Ȃ�A�s�U, B�s�T�����ꂼ��w�������ق�������
        cout << A*X + B*Y << endl;
    } else {                      // A + B > 2C�̏ꍇ�A
        if (X < Y){             // X < Y �Ȃ�2C�� AB�s�U�𔃂��B
            ans += 2*C * X;
            if (B > 2*C)        // B > 2+C�̏ꍇ�AAB�s�U�𔃂����ق�������
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
