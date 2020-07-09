#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size(),max1 = 0,max2 = 0,i = 0;

    for (int first = 0; first < n; ++first) {
        if (numbers[first] > max1) {
          max1 = numbers[first];
          i = first;
        }
    }

    for (int first = 0; first < n; ++first) {
      if(i != first && numbers[first] > max2) {
        max2 = numbers[first];
      }
    }

    return (long long)max2 * max1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
