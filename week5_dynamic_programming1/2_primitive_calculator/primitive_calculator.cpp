#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> v(n+1,INT_MAX);
  v[0] = v[1] = 0;
  for(int i=2;i<=n;i++) {
    int t1 = INT_MAX,t2=INT_MAX,t3=INT_MAX;
    t1 = v[i-1] + 1;
    if(i %2 ==0) t2 = v[i/2] +1;
    if(i %3 ==0) t3 = v[i/3] +1;
    int mi = t1<t2?t1:t2;
    mi = mi<t3?mi:t3;
    v[i] = mi;
  }
  sequence.push_back(n);

  while(n!=1) {
    if(n%3==0 && v[n]-1 == v[n/3]) {
      sequence.push_back(n/3);
      n /= 3;
    }else if(n%2==0 && v[n]-1 == v[n/2]) {
      sequence.push_back(n/2);
      n /= 2;
    }else {
      sequence.push_back(n-1);
      n-=1;
    }
  }

  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (int i = sequence.size()-1; i >= 0; i--) {
    std::cout << sequence[i] << " ";
  }
}
