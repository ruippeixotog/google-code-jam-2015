#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

#define MAXN 15
#define INF 1e9

#define ll long long

using namespace std;

typedef pair<int, int> Point;

Point trees[MAXN];

ll cross(Point& o, Point& a, Point& b) {
  return (a.first - o.first) * (ll) (b.second - o.second) -
    (a.second - o.second) * (ll) (b.first - o.first);
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

        for(int j = 0; j < n; j++) {
          if(j == i) continue;

          int cuts = 0;
          for(int k = 0; k < n; k++) {
            if(k != i && k != j &&
              cross(trees[i], trees[j], trees[k]) < 0) cuts++;
          }
          minCuts = min(minCuts, cuts);
        }
        cout << minCuts << endl;
      }
    }
  }
  return 0;
}
