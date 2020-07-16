#include <iostream>
#include <vector>

using namespace std;

int partition3(vector<int> &A) {
  //write your code here
  if(A.size() < 3)
    return 0;
  int sum = 0;
  for(int i =0;i<A.size();i++)
    sum += A[i];
  if(sum%3)
      return 0;
  int w = sum/3,n=A.size();
  int count = 0;
  vector<vector<int> > v(w+1,vector<int>(n+1,0));

  for(int i=1;i<=w;i++) {
    for(int j=1;j<=n;j++) {
      v[i][j] = v[i][j-1];
      if(A[j-1]<=i) {
        int temp = v[i-A[j-1]][j-1]+A[j-1];
        if(temp > v[i][j])
          v[i][j] = temp;
      }
      if(v[i][j] == w)
        count++;
    }
  }
  if(count<3)
    return 0;
  else
    return 1;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
