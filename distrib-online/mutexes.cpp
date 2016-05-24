#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

#include "mutexes.h"
#include "message.h"

#define MAXOP 10000
#define INF 1000000000

using namespace std;

bool dp[MAXOP + 1][MAXOP + 1];

int main() {
  if (MyNodeId() != 0) return 0;

  dp[0][0] = true;

  int best = INF;
  set<int> locked0;
  for(int i = 0; i < NumberOfOperations(0); i++) {
    int op0 = GetOperation(0, i);

    set<int> locked1;
    for(int j = 0; j < NumberOfOperations(1); j++) {
      int op1 = GetOperation(1, j);

      if(dp[i][j]) {
        bool hasNext = false;
        if(!locked1.count(op0)) { dp[i + 1][j] = true; hasNext = true; }
        if(!locked0.count(op1)) { dp[i][j + 1] = true; hasNext = true; }

        if(!hasNext) best = min(best, i + j + 2);
      }

      if(op1 > 0) locked1.insert(op1);
      else locked1.erase(-op1);
    }

    if(op0 > 0) locked0.insert(op0);
    else locked0.erase(-op0);
  }

  if(best == INF) printf("OK\n");
  else printf("%d\n", best);
  return 0;
}
