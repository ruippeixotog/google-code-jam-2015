#include <algorithm>
#include <iostream>

#define MAXD 100

using namespace std;

typedef long long ll;

int ds[MAXD];

int main() {
  int t; cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int c, d, v; cin >> c >> d >> v;
    for (int i = 0; i < d; i++)
      cin >> ds[i];

    sort(ds, ds + d);

    ll maxVal = 0; int oldIdx = 0, newCnt = 0;
    while(maxVal < v) {
      if(oldIdx < d && ds[oldIdx] <= maxVal + 1) {
        maxVal += ds[oldIdx] * c; oldIdx++;
      } else {
        maxVal += (maxVal + 1) * c; newCnt++;
      }
    }

    cout << "Case #" << tc << ": " << newCnt << endl;
  }
  return 0;
}
