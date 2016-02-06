#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int r, c, w; cin >> r >> c >> w;

    int res = r * (c / w) + w - (c % w == 0);
    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
