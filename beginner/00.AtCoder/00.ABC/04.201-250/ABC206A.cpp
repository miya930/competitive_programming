#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if ((int)(n*1.08) < 206) cout << "Yay!" << endl;
    else if ((int)(n*1.08) == 206) cout << "so-so" << endl;
    else cout << ":(" << endl;
}
