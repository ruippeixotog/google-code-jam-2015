#include <iostream>

#define MAXE 14

#define ll long long

using namespace std;

ll powMem[MAXE + 1];

ll curr; int res;

ll pow10(int ord) {
  if(ord == 0) return 1;
  if(!powMem[ord]) {
    ll halfPow = pow10(ord / 2);
    powMem[ord] = halfPow * halfPow * (ord % 2 == 0 ? 1 : 10);
  }
  return powMem[ord];
}

ll reversed(ll k) {
  ll revd = 0;
  while(k > 0) {
    revd = revd * 10 + k % 10;
    k /= 10;
  }
  return revd;
}

ll nextJump(int ord) {
  ll high = pow10((ord + 1) / 2 + 1) - 1;
  return high * pow10(ord / 2 + 1) + 1;
}

void countTo(ll target) {
  res += target - curr;
  curr = target;
}

void jump() {
  res++;
  curr = reversed(curr);
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    ll n; cin >> n;
    res = 0; curr = 0;

    int ord = 0;
    while(n >= nextJump(ord)) {
      countTo(reversed(nextJump(ord)));
      jump();
      ord++;
    }

    if(n > pow10(ord + 1)) {
      ll high = n / pow10(ord / 2 + 1);
      if(n % pow10(ord / 2 + 1) == 0) high--;
      ll cnt = pow10(ord + 1) + reversed(high);

      countTo(cnt);
      if(curr != reversed(curr)) jump();
    }

    countTo(n);
    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
