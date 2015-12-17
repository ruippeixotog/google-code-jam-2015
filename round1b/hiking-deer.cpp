#include <iostream>
#include <queue>
#include <utility>

#define ll long long

using namespace std;

typedef pair<ll, pair<int, ll>> Event;

Event make_event(ll t, int delta, ll m) {
  return make_pair(-t, make_pair(delta, m));
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    priority_queue<Event> events;
    int hikers = 0;

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      int d, h, m; cin >> d >> h >> m;

      hikers += h;
      for(int j = 0; j < h; j++) {
        ll mj = m + j;
        events.push(make_event(mj * (360 - d), -1, mj * 360));
      }
    }

    int curr = hikers, best = hikers;
    for(int i = 0; i < hikers * 2; i++) {
      Event ev = events.top(); events.pop();

      best = min(best, curr);
      curr += ev.second.first;

      ll m = ev.second.second;
      events.push(make_event(-ev.first + m, 1, m));
    }
    
    cout << "Case #" << tc << ": " << best << endl;
  }
  return 0;
}
