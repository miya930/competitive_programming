#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<pair<int, int> > prime(int n) {
    vector<pair<int, int> > res;

    for (int i = 2; i*i <= n; ++i) {
        if (n%i != 0) continue;

        int ex = 0;
        while(n%i == 0) {
            ex++;
            n /= i;
        }
        res.push_back(make_pair(i, ex));
    }
    if (n != 1) res.push_back(make_pair(n, 1));

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int> > vec = prime(n);
    
    printf("%d:", n);

    for (int i = 0; i < (int)vec.size(); ++i) {
        for (int j = 0; j < vec[i].second; ++j) {
            printf(" %d", vec[i].first);
        }
    }
    printf("\n");

}
