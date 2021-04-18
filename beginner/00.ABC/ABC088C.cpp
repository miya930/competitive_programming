#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int c[3][3];
    int a[3], b[3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    a[0] = 0;                           // a[0]‚ğŒÅ’è
    b[0] = c[0][0] - a[0];              // a[0]‚©‚ç‹‚Ü‚é
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];

/* a[1]‚ğ c[1][0] - b[0], c[1][1] - b[1], c[1][2] - b[2]
   ‚Ì3’Ê‚è‚ÅŒvZ‚µ‚Äˆê’v‚·‚ê‚ÎOK, a[2]‚à“¯—l */
   int a10 = c[1][0] - b[0];
   int a11 = c[1][1] - b[1];
   int a12 = c[1][2] - b[2];
   int a20 = c[2][0] - b[0];
   int a21 = c[2][1] - b[1];
   int a22 = c[2][2] - b[2];

   if ((a10 == a11) && (a11 == a12)&& (a20 == a21) && (a21 == a22))
        cout << "Yes" << endl;
   else
        cout << "No" << endl;
}
