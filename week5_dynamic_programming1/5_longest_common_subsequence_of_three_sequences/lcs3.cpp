#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int m = a.size(),n = b.size(),l=c.size();
  vector<vector<vector<int> > > v(m+1,vector<vector<int> >(n+1,vector<int>(l+1)));

for(int i = 0;i<=m;i++) {
  for(int j = 0;j<=n;j++) {
    for(int k = 0;k<=l;k++) {
      if(i==0||j==0||k==0){
        v[j][j][k] =0;continue;
      }
      else if(a[i-1] == b[j-1] && a[i-1] == c[k-1]) {
        v[i][j][k] = v[i - 1][j - 1][k - 1] + 1;continue;
      }else{
        v[i][j][k] = max(max(v[i-1][j][k],v[i][j-1][k]),v[i][j][k-1]);
      }
    }
  }
}

  return v[m][n][l];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
