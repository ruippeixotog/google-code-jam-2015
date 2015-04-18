#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#define ll long long

#define MAXB 1000
#define MAXM 100000

using namespace std;

int b, n;
int m[MAXB];

ll servedAt(ll t) {
  ll served = 0;
  for(int i = 0; i < b; i++) served += (t / m[i]) + 1;
  return served;
}

ll bs(ll low, ll high) {
  if(low == high) return low;
  ll mid = (high + low) / 2;

  return servedAt(mid) >= (n - b - 1) ? bs(low, mid) : bs(mid + 1, high);
}

int sim(ll served, ll t) {
  priority_queue<pair<int, int> > q;
  for(int i = 0; i < b; i++) {
    int left = t % m[i];
    if(left == 0) left = m[i];
    q.push(make_pair(-left, -i));

    cerr << i << " - " << left << endl;
  }

  int last = -1;

  while(served < n) {
    pair<int, int> next = q.top(); q.pop();
    last = -next.second;
    cerr << last << " at " << -next.first << endl;
    q.push(make_pair(-(-next.first + m[last]), -last));
    served++;
  }

  return last + 1;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> b >> n;
    for(int i = 0; i < b; i++) cin >> m[i];

    ll t = bs(0, MAXM * (ll) n);
    ll served = servedAt(t);

    cerr << "t=" << t << "(served " << served << " of " << n << ")" << endl;

    cout << "Case #" << tc << ": " << sim(served, t) << endl;
  }
  return 0;
}
