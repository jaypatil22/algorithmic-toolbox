#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
//using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int start = 0;
    stops.push_back(dist);
    int n = stops.size();
    int current = -1;
    int refills = 0;

    while(current < (n-1))
    {
      //std::cout << stops.size() << '\n';
      while(current < n-1 && stops[current + 1] - start <= tank)
      {
        current += 1;
        //std::cout << stops[current] << '\n';
      }
      if(current == n-1)
        return refills;
      if(current == -1 || start == stops[current])
        return -1;
      start = stops[current];
      refills += 1;
    }

    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops[i];

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
