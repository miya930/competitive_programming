#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    int sum_alice = 0, sum_bob = 0;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    
    sort(a.rbegin(), a.rend());
    
    for (int i = 0; i < N; i+=2) {
        sum_alice += a[i];
        if (i+1 < N)
            sum_bob += a[i+1];
    }

    cout << sum_alice - sum_bob << endl; 
}
