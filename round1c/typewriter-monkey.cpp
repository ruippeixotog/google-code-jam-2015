#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>

#define MAXL 100
#define MAXS 100

using namespace std;

typedef long double ld;

int pi[MAXS];
map<char, int> freq;
ld dp[MAXS + 1][MAXS + 1][MAXL];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int k, l, s; cin >> k >> l >> s;
    string keyb, target; cin >> keyb >> target;

    freq.clear();
    for(int i = 0; i < k; i++) freq[keyb[i]]++;

    pi[0] = 0;
    for(int i = 1; i < target.size(); i++) {
      pi[i] = pi[i - 1];
      while(pi[i] > 0 && target[pi[i]] != target[i])
        pi[i] = pi[pi[i] - 1];
      if(target[pi[i]] == target[i]) pi[i]++;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1.0;

    for(int i = 0; i < s; i++) {
      for(int j = 0; j < l; j++) {
        for(int m = 0; m < s; m++) {
          for(auto entry : freq) {
            char ch = entry.first;
            ld prob = dp[i][m][j] * entry.second / (ld) k;

            int jp = j;
            while(jp > 0 && ch != target[jp])
              jp = pi[jp - 1];
            if(ch == target[jp]) jp++;

            if(jp == l) dp[i + 1][m + 1][pi[jp - 1]] += prob;
            else dp[i + 1][m][jp] += prob;
          }
        }
      }
    }

    int maxB = 0; ld avg = 0.0;
    for(int i = 1; i <= s; i++) {
      for(int j = 0; j < l; j++) {
        if(dp[s][i][j] > 0.0) maxB = i;
        avg += dp[s][i][j] * i;
      }
    }
    cout << "Case #" << tc << ": " << setprecision(9) << (maxB - avg) << endl;
  }
  return 0;
}
