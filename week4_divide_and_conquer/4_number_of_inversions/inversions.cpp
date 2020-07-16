#include <iostream>
#include <vector>

using std::vector;

long long merge(std::vector<int> &a, vector<int> &b, size_t left,size_t mid, size_t right) {
  size_t i = left, j=mid+1,k=left;
  long long inv = 0;
  while(i <= mid && j <= right) {
    if(a[i] <= a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      inv += j - k;
      j++;
    }
    k++;
  }

  while(i <= mid) {
    b[k] = a[i];
    i++;k++;
  }
  while(j <= right) {
    b[k] = a[j];
    j++;k++;
  }
  for(i=left;i<=right;i++) {
    a[i] = b[i];
  }
  return inv;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left ) return number_of_inversions;
  size_t ave = left + (right-left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions += merge(a,b,left,ave,right);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
  //for(int x = 0 ;x< a.size();x++) {
    //std::cout << a[x] << '\n';
  //}
}
