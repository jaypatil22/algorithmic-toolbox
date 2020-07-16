#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int m= str1.size(),n=str2.size();
  vector<vector<int>> v(m+1,vector<int>(n+1));

  for(int i=0;i<=m;i++) {
    for(int j=0;j<=n;j++) {
      if(i==0)
        v[i][j] = j;
      else if (j==0) {
          v[i][j] = i;
      }else if(str1[i-1] == str2[j-1])
        v[i][j] = v[i-1][j-1];
      else
        v[i][j] = 1 + min(min(v[i][j-1],v[i-1][j]),v[i-1][j-1]);
    }
  }

  return v[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
