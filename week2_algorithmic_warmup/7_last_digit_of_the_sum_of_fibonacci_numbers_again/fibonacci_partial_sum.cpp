#include <iostream>
#include <vector>
using std::vector;


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current % 10;
        current = (tmp_previous + current) % 10;
        sum += (current % 10);
    }

    if(current == 0)
      return 9;
    else
      return current - 1;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {

  if (to <= 1) {
    return to;
  }

  from = (from+1) % 60;
  to = (to + 2) % 60;
  int a = fibonacci_sum_naive(to);
  int b = fibonacci_sum_naive(from);

  if( <= 1) {
    a = from - 1;
  }
  if(from <= 1) {
    b = from - 1;
  }

  if (a >= b) {
    return a-b;
  } else {
    return (10 + a - b);
  }


}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
