#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool greater(string a,string max) {
  std::stringstream b(a+max);
  std::stringstream c(max+a);

  int d,e;
  b >> d; c >> e;
  return d >= e;
}

string largest_number(vector<string> a) {
  std::stringstream ret;
  int n = a.size();
  while(n > 1){
    string maxdi = a[0];
    int index=0;
    for(int i=1;i<n;i++) {
      if(greater(a[i],maxdi)) {
        maxdi = a[i];
        index = i;
      }
    }
      n--;
      string temp = a[n];
      a[n] = a[index];
      a[index] = temp;
      //std::cout << maxdi << n <<'\n';
      ret << maxdi;
  }
  ret << a[0];
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
