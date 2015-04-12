#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define MAXP 1000

using namespace std;

int hist[MAXP + 1];

map<vector<int>, int> mem;

int bf(int t, vector<int> state) {
  // for(int i = 0; i < t; i++) cerr << "  ";
  // cerr << "state: "; 
  // for(int i = 0; i < state.size(); i++) cerr << state[i] << " ";
  // cerr << endl;

  sort(state.begin(), state.end());

  if(state.empty()) return 0;
  if(mem.count(state)) return mem[state];

  int best = 1e9;

  for(int i = 0; i < state.size(); i++) {
    if(state[i] == 1) continue;

    for(int p = 1; p < state[i]; p++) {

      vector<int> newState;
      for(int j = 0; j < state.size(); j++) {
        if(j != i) newState.push_back(state[j]);
        else {
          newState.push_back(p);
          newState.push_back(state[j] - p);
        }
      }
      best = min(best, 1 + bf(t + 1, newState));
    }
  }

  vector<int> newState2;
  for(int i = 0; i < state.size(); i++) {
    if(state[i] > 1)
      newState2.push_back(state[i] - 1);
  }
  best = min(best, 1 + bf(t + 1, newState2));

  mem[state] = best;
  return best;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cerr << "Case " << tc << endl;
    int d; cin >> d;

    vector<int> vec;
    for(int i = 0; i < d; i++) {
      int pi; cin >> pi; vec.push_back(pi);
    }
    int best = bf(0, vec);

    // memset(hist, 0, sizeof(hist));
    // for(int i = 0; i < d; i++) {
    //   int pi; cin >> pi; hist[pi]++;
    // }

    // int best = (int) 1e9;
    // int specials = 0;

    // for(int i = MAXP; i > 1; i--) {
    //   if(hist[i] == 0) continue;

    //   best = min(best, i + specials);
    //   int major = (i + 1) / 2, minor = i / 2;
    //   hist[minor] += hist[i];
    //   hist[major] += hist[i];
    //   specials += hist[i];
    // }

    // best = min(best, 1 + specials);
    cout << "Case #" << tc << ": " << best << endl;
  }
  return 0;
}
