#include <algorithm>
#include <cstdio>
#include <cstring>

#include "mutexes.h"
#include "message.h"

#define MAXOP 10000
#define MAXLOCK 100000
#define INF 1000000000

using namespace std;

bool dp[MAXOP + 1][MAXOP + 1];
bool locked0[MAXLOCK + 1], locked1[MAXLOCK + 1];

int main() {
  if (MyNodeId() != 0) return 0;

  dp[0][0] = true;

  int best = INF;
  for(int i = 0; i < NumberOfOperations(0); i++) {
    int op0 = GetOperation(0, i);

    memset(locked1, false, sizeof(locked1));
    for(int j = 0; j < NumberOfOperations(1); j++) {
      int op1 = GetOperation(1, j);

      if(dp[i][j]) {
        bool hasNext = false;
        if(op0 < 0 || !locked1[op0]) { dp[i + 1][j] = true; hasNext = true; }
        if(op1 < 0 || !locked0[op1]) { dp[i][j + 1] = true; hasNext = true; }

        if(!hasNext) best = min(best, i + j + 2);
      }

      if(op1 > 0) locked1[op1] = true;
      else locked1[-op1] = false;
    }

    if(op0 > 0) locked0[op0] = true;
    else locked0[-op0] = false;
  }

  if(best == INF) printf("OK\n");
  else printf("%d\n", best);
  return 0;
}
