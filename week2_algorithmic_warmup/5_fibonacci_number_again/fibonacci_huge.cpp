#include <iostream>
#include <bits/stdc++.h>

long long pasino(long long m) {
  long long previous = 0, current = 1;

  for (long long i =0; i < m*m; i++){
    long long temp = previous;
    previous = current;
    current = (temp + previous) % m;

    if(current == 1 && previous == 0)
      return i+1;

  }
}

unsigned long long get_fibonacci_huge_naive(long long n,long long m) {
  if(n <= 1)
    return n;

  unsigned long long previous = 0, current = 1;

  for(unsigned long long i=2;i<=n; i++) {
    unsigned long long temp = previous;
    previous = current % m;
    current = temp + previous;
  }

  return current;
}

long long get_fibonacci_huge_fast(long long n,long long m) {

  long long pasino_ = pasino(m);
  //std::cout << pasino_ << '\n';
  n = n % pasino_;

  unsigned long long res = get_fibonacci_huge_naive(n, m);
  //std::cout << res << '\n';
  return res % m;


}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
