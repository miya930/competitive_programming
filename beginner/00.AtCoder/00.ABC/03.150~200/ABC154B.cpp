#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    string S;
    cin >> S;

    for (int i = 0; i < S.size(); i++)
        S[i] = 'x';
    
    cout << S << endl;
}
