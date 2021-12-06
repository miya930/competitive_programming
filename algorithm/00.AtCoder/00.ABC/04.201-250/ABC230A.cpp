#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    if (n >= 42) n++;
    string str = "AGC0";
    if (n < 10) str = str + "0";
    str = str + to_string(n);

    cout << str << endl;

    return 0;
}
