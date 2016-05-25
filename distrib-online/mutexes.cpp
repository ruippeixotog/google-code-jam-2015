#include <algorithm>
#include <cstdio>
#include <cstring>

#include "mutexes.h"
#include "message.h"

#define MAXOP 40000
#define MAXLOCK 100000
#define INF 1000000000
#define BATCH_SIZE 400

using namespace std;

bool dp[MAXOP + 1][MAXOP / 100 + 2];
bool locked0[MAXLOCK + 1], baseLocked1[MAXLOCK + 1], locked1[MAXLOCK + 1];

int main() {
  int nodeBegin = (MyNodeId() * NumberOfOperations(1) / NumberOfNodes());
  int nodeEnd = ((MyNodeId() + 1) * NumberOfOperations(1) / NumberOfNodes());

  if(nodeBegin == 0)
    dp[0][0] = true;

  for(int j = 0; j < nodeBegin; j++) {
    int op1 = GetOperation(1, j);
    if(op1 > 0) baseLocked1[op1] = true;
    else baseLocked1[-op1] = false;
  }

  int best = INF, batchBegin = 0;
  for(int i = 0; i < NumberOfOperations(0); i++) {
    int op0 = GetOperation(0, i);

    if(i % BATCH_SIZE == 0)
      batchBegin = i;

    if(MyNodeId() != 0 && i == batchBegin) {
      Receive(MyNodeId() - 1);
      for(int i2 = i; i2 < min(i + BATCH_SIZE, NumberOfOperations(0)); i2++)
        dp[i2][0] = (bool) GetInt(MyNodeId() - 1) || dp[i2][0];
    }

    memcpy(locked1, baseLocked1, sizeof(locked1));
    for(int j = 0; j < nodeEnd - nodeBegin; j++) {
      int op1 = GetOperation(1, nodeBegin + j);

      if(dp[i][j]) {
        bool hasNext = false;
        if(op0 < 0 || !locked1[op0]) { dp[i + 1][j] = true; hasNext = true; }
        if(op1 < 0 || !locked0[op1]) { dp[i][j + 1] = true; hasNext = true; }

        if(!hasNext) best = min(best, i + nodeBegin + j + 2);
      }

      if(op1 > 0) locked1[op1] = true;
      else locked1[-op1] = false;
    }

    if(MyNodeId() != NumberOfNodes() - 1 &&
      ((i + 1) % BATCH_SIZE == 0 || i == NumberOfOperations(0) - 1)) {

      for(int i2 = batchBegin; i2 <= i; i2++)
        PutInt(MyNodeId() + 1, dp[i2][nodeEnd - nodeBegin]);
      Send(MyNodeId() + 1);
    }

    if(op0 > 0) locked0[op0] = true;
    else locked0[-op0] = false;
  }

  if(MyNodeId() != 0) {
    PutInt(0, best); Send(0);
  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k); best = min(best, GetInt(k));
    }
    if(best == INF) printf("OK\n");
    else printf("%d\n", best);
  }
  return 0;
}
