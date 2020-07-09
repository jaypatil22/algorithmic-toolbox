#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    //long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current % 10;
        current = (tmp_previous + previous) % 10;
        //sum += (current % 10);
    }


      return current;
}


int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long ln = n%60;
    long long lnp = (n+1) %60;

    int a = fibonacci_sum_naive(ln);
    int b = fibonacci_sum_naive(lnp);

    if(ln <= 1)
      a = ln;
    if(lnp <= 1)
      b = lnp;

    return (a*b) % 10;

}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
