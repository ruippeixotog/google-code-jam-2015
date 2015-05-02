#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    int d1, m1, d2, m2;

    for(int i = 0; i < n; i++) {
      int d, h, m; cin >> d >> h >> m;

      if(h == 2) { d1 = d2 = d; m1 = m; m2 = m + 1; }
      else if(i == 0) { d1 = d; m1 = m; }
      else { d2 = d; m2 = m; }
    }

    if(m1 < m2) { // make sure h2 is always faster
      int tmp = m1; m1 = m2; m2 = tmp;
      tmp = d1; d1 = d2; d2 = tmp;
    }

    double v1 = 360 / (double) m1;
    double v2 = 360 / (double) m2;

    double t1 = (360 - d1) / v1; // time for h1 to reach the end
    double x2 = d2 + v2 * t1; // where is h2 at that time?

    int res = x2 >= 720 ? 1 : 0; 
    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
