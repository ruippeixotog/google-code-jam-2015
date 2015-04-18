#include <algorithm>
#include <iostream>

#define MAXN 10000

using namespace std;

int m[MAXN];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> m[i];

    int eatenA = 0;
    int last = m[0];
    int maxDown = 0;
    for(int i = 1; i < n; i++) {
      if(m[i] < last) {
        eatenA += last - m[i];
        maxDown = max(maxDown, last - m[i]);
      }
      last = m[i];
    }

    int eatenB = 0;
    for(int i = 0; i < n - 1; i++)
      eatenB += min(m[i], maxDown);

    cout << "Case #" << tc << ": " << eatenA << " " << eatenB << endl;
  }
  return 0;
}
