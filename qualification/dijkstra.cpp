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

int divTableL[4][4] = {
  {1, -2, -3, -4},
  {2,  1,  4, -3},
  {3, -4,  1,  2},
  {4,  3, -2,  1}
};

int divTableR[4][4] = {
  {1, -2, -3, -4},
  {2,  1, -4,  3},
  {3,  4,  1, -2},
  {4, -3,  2,  1}
};

int repr(char ch) { return (ch - 'i') + 2; }

// q0 * q1 = qmult(q0,q1)
int qmult(int q0, int q1) {
  return (q0 * q1 < 0 ? -1 : 1) * multTable[abs(q0)-1][abs(q1)-1];
}

// q0 * qdivl(qr,q0) = qr
int qdivl(int qr, int q0) {
  return (qr * q0 < 0 ? -1 : 1) * divTableL[abs(qr)-1][abs(q0)-1];
}

// qdivr(qr,q1) * q1 = qr
int qdivr(int qr, int q1) {
  return (qr * q1 < 0 ? -1 : 1) * divTableR[abs(qr)-1][abs(q1)-1];
}

int qpow(int q0, int k) {
  int curr = 1;
  for(int i = 0; i < k; i++) curr = qmult(curr, q0);
  return curr;
}

int existsPrefix[9], existsSuffix[9];
int allStrProd;

void preprocess(string& str) {
  int vals[MAXL];
  for(int i = 0; i < str.size(); i++)
    vals[i] = repr(str[i]);

  memset(existsPrefix, 0, sizeof(existsPrefix));
  memset(existsSuffix, 0, sizeof(existsSuffix));

  int curr = 1;
  for(int i = 0; i < str.size(); i++) {
    curr = qmult(curr, vals[i]);
    if(!existsPrefix[curr + 4]) existsPrefix[curr + 4] = i + 2;
  }

  curr = 1;
  for(int i = str.size() - 1; i >= 0; i--) {
    curr = qmult(vals[i], curr);
    if(!existsSuffix[curr + 4]) existsSuffix[curr + 4] = i + 2;
  }

  allStrProd = curr;
}

// split: (string)* st|rin|g (string)*
bool case1(int x) {
  for(int a = 0; a <= min(4, x - 1); a++) {
    int aPow = qpow(allStrProd, a);
    int prefix = qdivl(repr('i'), aPow);
    if(!existsPrefix[prefix + 4]) continue;

    int c = x - a - 1;
    int cPow = qpow(allStrProd, c);
    int suffix = qdivr(repr('k'), cPow);
    if(!existsSuffix[suffix + 4] ||
      existsPrefix[prefix + 4] > existsSuffix[suffix + 4]) continue;

    int bMid = qdivr(qdivl(allStrProd, prefix), suffix);
    if(bMid == repr('j'))
      return true;
  }
  return false;
}

// split: (string)* st|ring (string)* strin|g (string)*
bool case2(int x) {
  for(int a = 0; a <= min(4, x - 2); a++) {
    int aPow = qpow(allStrProd, a);
    int prefix1 = qdivl(repr('i'), aPow);
    if(!existsPrefix[prefix1 + 4]) continue;

    int suffix1 = qdivl(allStrProd, prefix1);

    for(int b = 0; b <= min(4, x - a - 2); b++) {
      int bPow = qpow(allStrProd, b);
      int prefix2 = qdivl(repr('j'), qmult(suffix1, bPow));
      if(!existsPrefix[prefix2 + 4]) continue;

      int suffix2 = qdivl(allStrProd, prefix2);

      int c = x - a - b - 2;
      int cPow = qpow(allStrProd, c);
      if(qmult(suffix2, cPow) == repr('k'))
        return true;
    }
  }
  return false;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    ll l, x; cin >> l >> x;
    string str; cin >> str;

    int adjX = (int) min(x, 12 + x % 4);
    preprocess(str);

    bool found = case1(adjX) || case2(adjX);
    cout << "Case #" << tc << ": " << (found ? "YES" : "NO") << endl;
  }
  return 0;
}
