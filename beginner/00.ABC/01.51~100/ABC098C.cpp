#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    string S;
    cin >> N >> S;
    vector<int> east(N+1, 0), west(N+1, 0);

    for (int i = 0; i < N; i++) {
        if (S[i] == 'W') 
            west[i+1] = west[i] + 1;
        west[i+1] = max(west[i+1], west[i]);

    }
    for (int i = N-1; i >= 0; i--) {
        if (S[i] == 'E')
            east[i] = east[i+1] + 1;
        east[i] = max(east[i], east[i+1]);
    }
    int ans = 100000000;
    for (int i = 0; i < N; i++)
        ans = min(ans, west[i]+east[i+1]);
    
    cout << ans << endl;
}
