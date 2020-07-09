#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  while(capacity > 0 ) {
    double max = 0.0;
    int i = 0;
    for(int j=0;j<weights.size();j++) {
      double temp = (double) values[j] / weights[j];
      if(temp > max) {
        max = temp;
        i = j;
      }

    }
    if(weights[i] == 0)
      break;
    int a = (capacity < weights[i]) ? capacity : weights[i];
    value += (double)a * max;
    weights[i] -= a;
    capacity -= a;
    values[i] -= max * a;

  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
