#include <iostream>


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    n = (n+2) % 60;

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

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
