#include <algorithm>
#include <iostream>
#include <vector>

#define MAXN 15

#define ll long long

using namespace std;

struct Point {
  ll x, y;
 
  bool operator <(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

ll cross(Point &O, Point &A, Point &B) {
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> P) {
  int n = P.size(), k = 0;
  vector<Point> H(2*n);
 
  for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
 
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
    H[k++] = P[i];
  }
 
  H.resize(k);
  return H;
}

Point treesOrig[MAXN];
Point trees[MAXN];

int solve(int n, int k, vector<Point>& pts, Point& curr) {
  if(k == n) {
    vector<Point> hull = convexHull(pts);

    for(int j = 0; j < hull.size(); j++)
      if(hull[j].x == curr.x && hull[j].y == curr.y)
        return 0;

    return 1e9;
  }

  pts.push_back(trees[k]);
  int opt1 = solve(n, k + 1, pts, curr);
  pts.pop_back();

  int opt2 = 1 + solve(n, k + 1, pts, curr);
  return min(opt1, opt2);
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> trees[i].x >> trees[i].y;
      treesOrig[i] = trees[i];
    }
    
    sort(trees, trees + n);

    cout << "Case #" << tc << ":" << endl;

    vector<Point> state;
    for(int i = 0; i < n; i++) {
      cout << solve(n, 0, state, treesOrig[i]) << endl;
    }
  }
  return 0;
}
