#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::pair;
using std::min;

struct point {
  int x,y;
};

double dist (point a,point b) {
  return sqrt(pow((a.x - b.x),2) + pow((a.y-b.y),2));
}

int comparey(const void *a,const void *b) {
  point *c = (point *)a,*d = (point *)b;
  return (c->y-d->y);
}

double slow(point p[],int n) {
  double ret = FLT_MAX;
  for(int i= 0;i<n;i++)
    for(int j=i+1;j<n;j++)
      ret = min(ret, dist(p[i],p[j]));
  return ret;
}

double middle(point strip[],int size,double d) {
  double ret = d;
  qsort(strip,size,sizeof(point),comparey);
  for(int i= 0;i<size;i++)
    for(int j=i+1;j<size && (strip[j].y-strip[i].y) < d;j++)
      ret = min(ret,dist(strip[i],strip[j]));
  return ret;
}

double closest(point points[],int n) {
  if(n <= 4)
  return slow(points,n);

  int mid = n/2;
  point midpt = points[mid];
  double dl = closest(points, mid);
  double dr = closest(points+mid,n-mid);
  double dist = min(dl,dr);
  point strip[n];
  int j = 0;
  for(int i= 0;i<n;i++)
    if(abs(points[i].x-midpt.x) < dist)
      strip[j] = points[i];j++;
  return min(dist,middle(strip ,j,dist));
}

int comparex(const void *a,const void *b) {
  point *c = (point *)a,*d = (point *)b;
  return (c->x-d->x);
}

double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  int size = x.size();
  point points[size];
  for(int j=0;j<size;j++) {
    points[j].x = x[j];
    points[j].y = y[j];
  }
  qsort(points,size,sizeof(point),comparex);
  return closest(points,size);
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
