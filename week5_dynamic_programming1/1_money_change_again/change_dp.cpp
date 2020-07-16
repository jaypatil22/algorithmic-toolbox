#include <iostream>
#include <bits/stdc++.h>

int get_change(int m) {
  int res = 0;
  std::vector<int> v(m+1,INT_MAX);
  v[0] = 0;
  int c[] = {1,3,4};
  for(int i = 1;i<=m;i++)
    for(int j= 0; j<3;j++) {
      if(i >= c[j]) {
        int temp = v[i-c[j]];
        if(temp != INT_MAX && temp +1 < v[i])
          v[i] = temp+1;
      }
    }

    return v[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
