#include <cmath>
#include <cstdio>
#include <iostream>

#define ll long long

using namespace std;

double tRound(double x) {
  double order = 100000000.0;
  return round(x * order) / order;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    double v, x; cin >> v >> x;

    double res = 0.0;
    if(n == 1) {
      double r1, c1; cin >> r1 >> c1;
      res = c1 != x ? -1.0 : v / r1;
    } else if (n == 2) {
      double r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

      if(c1 == c2) {
        res = c1 != x ? -1.0 : v / max(r1, r2);
      } else {
        double t1 = (v * (x - c2)) / (r1 * (c1 - c2));
        double t2 = tRound((v - t1 * r1) / r2);

        res = (t1 < 0.0 || t2 < 0.0) ? -1.0 : max(t1, t2);
      }
    } else {
      res = -1.0; // not implemented
    }

    cout << "Case #" << tc << ": "; 
    if(res < 0.0) cout << "IMPOSSIBLE" << endl;
    else printf("%.8f\n", res);
  }
  return 0;
}
