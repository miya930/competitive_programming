#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<int> > a(N, vector<int>(M));
    vector<int> c(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> dp(N);
}
