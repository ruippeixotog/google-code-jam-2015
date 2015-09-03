#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

#define MAXN 15

#define ll long long

using namespace std;

typedef pair<int, int> Point;

Point trees[MAXN], treesOrig[MAXN];
Point hull[2 * MAXN];

ll cross(Point& o, Point& a, Point& b) {
  return (a.first - o.first) * (ll) (b.second - o.second) -
    (a.second - o.second) * (ll) (b.first - o.first);
}

int convexHull(vector<Point> pts) {
  int k = 0;
 
  for (int i = 0; i < pts.size(); i++) {
    while (k >= 2 && cross(hull[k - 2], hull[k - 1], pts[i]) < 0) k--;
    hull[k++] = pts[i];
  }

  for (int i = pts.size() - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross(hull[k - 2], hull[k - 1], pts[i]) < 0) k--;
    hull[k++] = pts[i];
  }
 
  return k;
}

int solve(int n, int k, vector<Point>& pts, Point& curr) {
  if(k == n) {
    int hullSize = convexHull(pts);

    for(int i = 0; i < hullSize; i++) {
      if(hull[i] == curr) return 0;
    }
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
      cin >> trees[i].first >> trees[i].second;
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
