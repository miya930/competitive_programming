#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> memo;

ll trib(int n)
{
    if (n == 0) return 0;
    else if(n == 1) return 0;
    else if(n == 2) return 1;

    if(memo[n] != -1) return memo[n];

    return memo[n] = trib(n-1) + trib(n-2) + trib(n-3);
}

int main(void)
{   
    int N;
    cin >> N;
    memo.assign(N+1, -1);
    trib(N); 

    for (int i = 0; i < N; i++)
        cout << "memo[" << i << "] = " << memo[i] << endl;
}
