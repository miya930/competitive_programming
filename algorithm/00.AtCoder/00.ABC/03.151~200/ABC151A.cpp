#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    char c;
    cin >> c;
    int a = c - 'a';
    a = (a+1)%26;
    cout << (char)(a+'a') << endl;

    return 0;
}
