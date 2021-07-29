#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;
typedef long long ll;
const int INF = 1000000007;
ll n, k;

int main()
{
   cin >> n >> k;
   for (int i = 0; i < n; ++i) {
       for (int j = 0; j < n; ++j) {
           int a;
           cin >> a;
           if (a == 1) {
               G[i].push_back(j);
           }
       } 
   } 

   
}


