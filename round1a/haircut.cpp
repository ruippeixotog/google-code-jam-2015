#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define MAXB 5

using namespace std;

int m[MAXB];

map<vector<int>, int> mem;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int b, n; cin >> b >> n;
    for(int i = 0; i < b; i++) cin >> m[i];

    mem.clear();
    vector<int> state(b, 0);

    bool jumped = false;
    int lowIdx;

    for(int i = 0; i < n; i++) {
      lowIdx = -1;
      int low = 1e9;
      for(int j = 0; j < b; j++) {
        if(state[j] < low) { low = state[j]; lowIdx = j; }
      }

      for(int j = 0; j < b; j++) state[j] -= low;
      // cerr << i << ": " << lowIdx << endl;

      if(!jumped) {
        if(mem.count(state)) {
          int period = i - mem[state];
          int jump = (n - i - 1) / period;
          i += period * jump;

          // cerr << "Jump to " << i << "!" << endl;
          jumped = true;
        } else {
          mem[state] = i;
        }
      }

      state[lowIdx] += m[lowIdx];
    }

    cout << "Case #" << tc << ": " << (lowIdx + 1) << endl;
  }
  return 0;
}
