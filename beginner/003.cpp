#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int >;

int main()
{
    int n;
    Graph G(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
}
