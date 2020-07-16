#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return 1;
  sort(a.begin(), a.end());
  int current = a[0],n = (int)a.size();
  int count = 1;
  for(int i=1;i<n;i++) {
    if(a[i] == current) {
      count += 1;
      if(count > n/2){
        //std::cout << n/2 << '\n';
        return 1;
      }
    } else {
      count = 1;
      current = a[i];
    }
  }
  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
