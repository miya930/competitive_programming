#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, L;
    cin >> N >> L;

    vector<string> s(N);
    for (int i = 0; i < N; i++)
        cin >> s[i];
    
    sort(s.begin(), s.end());

    for (int i = 0; i < N; i++)
        cout << s[i];
    cout << endl;
}
