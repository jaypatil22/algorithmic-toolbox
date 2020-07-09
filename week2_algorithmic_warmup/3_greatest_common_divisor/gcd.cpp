#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast (int a, int b) {
  if(a == 0) {
    return b;
  }
  if(b == 0) {
    return a;
  }
  int min, max;
  if(a > b) {
    min = b;
    max = a;
  } else {
    min = a;
    max = b;
  }
  if(max % min == 0) {
    return min;
  } else {
    return gcd_fast(min, max % min);
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << "\n";
  return 0;
}
