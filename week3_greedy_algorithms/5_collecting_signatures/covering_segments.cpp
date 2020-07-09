#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
//#include <bits/stdc++.h>

using std::vector;

struct Segment {
  int start, end;
};

struct less_than_key
{
    inline bool operator() (const Segment& struct1, const Segment& struct2)
    {
        return (struct1.end < struct2.end);
    }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), less_than_key());
  int i = 0;
  Segment current;
  while(i < segments.size()) {
    current = segments[i];
    while(i < segments.size() && current.end >= segments[i +1].start) {
      i +=1;
    }
    int a = current.end,b= segments[i].end;
    points.push_back(current.end);
    i += 1;
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
