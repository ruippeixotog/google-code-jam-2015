#include <algorithm>
#include <iostream>

#define MAXD 1000
#define MAXP 1000

using namespace std;

int diners[MAXD];
int dp[MAXP + 1][MAXP + 1];

void preprocess() {
  for(int i = 1; i <= MAXP; i++) {
    dp[i][0] = MAXP + 1; // large number

    for(int j = 1; j <= MAXP; j++) {
      dp[i][j] = i == j ? 0 : dp[i][j - 1];

      for(int k = 1; k < i; k++)
        dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
    }
  }
}

int main() {
  preprocess();

  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int d; cin >> d;
    for(int i = 0; i < d; i++) cin >> diners[i];

    int best = MAXP;
    for(int i = 1; i <= MAXP; i++) {
      int sum = 0;
      for(int j = 0; j < d; j++)
        sum += dp[diners[j]][i];

      best = min(best, sum + i);
    }

    cout << "Case #" << tc << ": " << best << endl;
  }
  return 0;
}
