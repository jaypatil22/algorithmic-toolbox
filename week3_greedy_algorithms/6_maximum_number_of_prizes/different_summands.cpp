#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int current = 1;
  n -= current;
  summands.push_back(current);
  while(n >= current+1) {
    current += 1;
    n -= current;
    summands.push_back(current);
  }
  summands[summands.size()-1] += n;
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
