#include <iostream>
#include <string>

#define ll long long

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cerr << "Case " << tc << endl;

    ll n; cin >> n;

    ll curr = 0;
    int res = 0;

    if(n < 10) res = n;
    else {
      ll order = 10;
      curr = 10;
      res = 10;

      while(n >= 9 * order + 1) {
        cerr << "Count to " << (order + 9) << endl;
        res += (order + 9) - curr;

        cerr << "Jump " << (order + 9) << " to " << (9 * order + 1) << endl;
        curr = 9 * order + 1;
        res++;
        order *= 10;
      }

      for(int i = 8; i > 1; i--) {
        if(n >= i * order + 1) {
          cerr << "Count to " << (order + i) << endl;
          res += (order + i) - curr;

          cerr << "Jump " << (order + i) << " to " << (i * order + 1) << endl;
          curr = i * order + 1;
          res++;
          break;
        }
      }

      res += n - curr;
    }

    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
