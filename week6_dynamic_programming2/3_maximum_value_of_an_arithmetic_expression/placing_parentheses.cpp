#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  int len = exp.size();
  int n = (len+1) / 2;
  vector<vector<long long> > mini(n,vector<long long>(n,0));
  vector<vector<long long> > maxi(n,vector<long long>(n,0));

  for(int i=0;i<n;i++){
    mini[i][i] = stoll(exp.substr(2*i,1));
    maxi[i][i] = stoll(exp.substr(2*i,1));
  }
  for(int i = 0;i<n-1;i++) {
    for(int j=0;j<n-i-1;j++) {
      int l= j+i+1;
      long long minv = LLONG_MAX;
      long long maxv = LLONG_MIN;
      for(int k=j;k<l;k++) {
        long long a = eval(mini[j][k],mini[k+1][l],exp[2*k+1]);
        long long b = eval(mini[j][k],maxi[k+1][l],exp[2*k+1]);
        long long c = eval(maxi[j][k],mini[k+1][l],exp[2*k+1]);
        long long d = eval(maxi[j][k],maxi[k+1][l],exp[2*k+1]);

        minv = min(minv,min(a,min(b,min(c,d))));
        maxv = max(maxv,max(a,max(b,max(c,d))));
      }
      mini[j][l] = minv;
      maxi[j][l] = maxv;
    }
  }
  return maxi[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
