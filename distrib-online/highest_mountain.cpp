#include <cstdio>
#include <cstring>

#include "highest_mountain.h"
#include "message.h"

#define MAXN 1000
#define MAXH 1e9

using namespace std;

typedef long double ld;

bool excluded[MAXN];

int main() {
  memset(excluded, false, sizeof(excluded));

  int nodeBegin = MyNodeId() * NumberOfPeaks() / NumberOfNodes();
  int nodeEnd = (MyNodeId() + 1) * NumberOfPeaks() / NumberOfNodes();

  for(int i = nodeBegin; i < nodeEnd; i++) {
    int hi = GetHeight(i);

    ld bestSlope = -MAXH - 1; int best = -1;
    for(int j = i - 1; j >= 0; j--) {
      ld slope = (GetHeight(j) - hi) / (ld) (i - j);
      if(slope > bestSlope) {
        if(best >= 0) excluded[best] = true;
        bestSlope = slope;
        best = j;
      }
    }

    bestSlope = -MAXH - 1; best = -1;
    for(int j = i + 1; j < NumberOfPeaks(); j++) {
      ld slope = (GetHeight(j) - hi) / (ld) (j - i);
      if(slope > bestSlope) {
        if(best >= 0) excluded[best] = true;
        bestSlope = slope;
        best = j;
      }
    }
  }

  if(MyNodeId() != 0) {
    for(int i = 0; i < NumberOfPeaks(); i++) {
      PutInt(0, excluded[i]);
    }
    Send(0);

  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k);
      for(int i = 0; i < NumberOfPeaks(); i++) {
        excluded[i] = GetInt(k) || excluded[i];
      }
    }

    int cnt = 0;
    for(int i = 0; i < NumberOfPeaks(); i++) {
      if(!excluded[i]) cnt++;
    }
    printf("%d\n", cnt);
  }

  return 0;
}
