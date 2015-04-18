#include <iostream>
#include <queue>
#include <utility>

#define ll long long
#define lli_min_queue priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > >

#define MAXB 1000
#define MAXM 100000

using namespace std;

int b; ll n;
int m[MAXB];

ll servedAt(ll t) {
  if(t < 0) return 0;
  ll served = b;
  for(int i = 0; i < b; i++) served += t / m[i];
  return served;
}

ll bs(ll low, ll high) {
  if(low == high - 1) return low;
  ll mid = (high + low) / 2;
  return servedAt(mid) >= n ? bs(low, mid) : bs(mid, high);
}

int sim(ll t, int k) {
  lli_min_queue q;
  for(int i = 0; i < b; i++) {
    int next = (t / m[i] + 1) * m[i];
    q.push(make_pair(next, i));
  }

  int last = -1;
  while(k--) {
    pair<ll, int> next = q.top(); q.pop();
    last = next.second;
    q.push(make_pair(next.first + m[last], last));
  }

  return last + 1;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> b >> n;
    for(int i = 0; i < b; i++) cin >> m[i];

    ll t = bs(-1, MAXM * n);
    ll remaining = n - servedAt(t);

    cout << "Case #" << tc << ": " << sim(t, remaining) << endl;
  }
  return 0;
}
