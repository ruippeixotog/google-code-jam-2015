#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define MAXN 3000
#define INF 1e9
#define EPS 1e-10

#define ll long long

using namespace std;

typedef pair<int, int> Point;

Point trees[MAXN];

double angle(Point& o, Point& a) {
  return atan2(a.second - o.second, a.first - o.first) / M_PI;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> trees[i].first >> trees[i].second;
    }

    cout << "Case #" << tc << ":" << endl;

    if(n == 1) {
      cout << 0 << endl;
    } else {
      for(int i = 0; i < n; i++) {
        int minCuts = INF;

        vector<double> angles;
        for(int j = 0; j < n; j++) {
          if(j == i) continue;
          double ang = angle(trees[i], trees[j]);
          angles.push_back(ang);
          angles.push_back(ang + 2);
        }

        sort(angles.begin(), angles.end());

        for(int j = 0; j < n; j++) {
          if(j == i) continue;
          double ang = angle(trees[i], trees[j]);

          int cuts = (int) distance(
            upper_bound(angles.begin(), angles.end(), ang + EPS),
            lower_bound(angles.begin(), angles.end(), ang + 1 - EPS));

          minCuts = min(minCuts, cuts);
        }
        cout << minCuts << endl;
      }
    }
  }
  return 0;
}
