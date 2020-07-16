#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  vector<vector<int> > v(n+1,vector<int>(W+1));
  for(int i=0;i<=n;i++) {
    for(int j=0;j<=W;j++) {
      if(i==0||j==0)
        v[i][j] = 0;
      else if(w[i-1] <= j)
          v[i][j] = max(w[i-1]+v[i-1][j-w[i-1]],v[i-1][j]);
      else
            v[i][j] = v[i-1][j];
    }
  }
  return v[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
