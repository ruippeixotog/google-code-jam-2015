#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#define ll long long

#define MAXL 10000

using namespace std;

int multTable[4][4] = {
  {1,  2,  3,  4},
  {2, -1,  4, -3},
  {3, -4, -1,  2},
  {4,  3, -2, -1}
};

int repr(char ch) { return (ch - 'i') + 2; }

int qmult(int q0, int q1) {
  return (q0 * q1 < 0 ? -1 : 1) * multTable[abs(q0)-1][abs(q1)-1];
}

int qpow(int q0, int k) {
  int curr = 1;
  for(int i = 0; i < k; i++) curr = qmult(curr, q0);
  return curr;
}

bool find(string& str, int l, int x) {
  int vals[MAXL];

  int prod = 1;
  for(int i = 0; i < l; i++) {
    vals[i] = repr(str[i]);
    prod = qmult(prod, vals[i]);
  }

  if(qpow(prod, x) != qmult(qmult(repr('i'), repr('j')), repr('k')))
    return false;

  int prefix = 1e9, suffix = -1;

  int curr = 1;
  for(int i = 0; i < min(4, x) * l; i++) {
    curr = qmult(curr, vals[i % l]);
    if(curr == repr('i')) { prefix = i; break; }
  }

  curr = 1;
  for(int i = 0; i < min(4, x) * l; i++) {
    curr = qmult(vals[(x * l - i - 1) % l], curr);
    if(curr == repr('k')) { suffix = x * l - i; break; }
  }

  return prefix < suffix;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int l; ll x; cin >> l >> x;
    string str; cin >> str;

    bool found = find(str, l, min(x, 12 + x % 4));
    cout << "Case #" << tc << ": " << (found ? "YES" : "NO") << endl;
  }
  return 0;
}
