#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {

  int min, max;
  if(a > b) {
    min = b;
    max = a;
  } else {
    min = a;
    max = b;
  }
  long long d = max;
  while(d % min != 0) {
    d += max;
  }

  return d;

}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << "\n";
  return 0;
}
