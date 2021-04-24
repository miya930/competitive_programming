#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    int A, B, C, D;
    string s;
    cin >> s;
    A = s[0] -'0'; B = s[1] - '0'; C = s[2] - '0'; D = s[3]  - '0';

    if (A+B+C+D==7) cout << A << '+' << B << '+' << C << '+' << D << '=' << 7 << endl;
    else if (A-B+C+D==7) cout << A << '-' << B << '+' << C << '+' << D << '=' << 7 << endl;
    else if (A+B-C+D==7) cout << A << '+' << B << '-' << C << '+' << D << '=' << 7 << endl;
    else if (A-B-C+D==7) cout << A << '-' << B << '-' << C << '+' << D << '=' << 7 << endl;
    else if (A+B+C-D==7) cout << A << '+' << B << '+' << C << '-' << D << '=' << 7 << endl;
    else if (A-B+C-D==7) cout << A << '-' << B << '+' << C << '-' << D << '=' << 7 << endl;
    else if (A+B-C-D==7) cout << A << '+' << B << '-' << C << '-' << D << '=' << 7 << endl;
    else if (A-B-C-D==7) cout << A << '-' << B << '-' << C << '-' << D << '=' << 7 << endl;

}
