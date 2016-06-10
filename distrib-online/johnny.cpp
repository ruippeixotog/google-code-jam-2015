#include <algorithm>
#include <cstdio>

#include "johnny.h"
#include "message.h"

#define MAXC 20000

using namespace std;

int degrees[MAXC];

int main() {
  int nodeBegin = (MyNodeId() * (int) NumberOfCards() / NumberOfNodes());
  int nodeEnd = ((MyNodeId() + 1) * (int) NumberOfCards() / NumberOfNodes());

  PutInt(0, nodeEnd - nodeBegin);
  for (int i = nodeBegin; i < nodeEnd; i++) {
    int cnt = 0;
    for(int j = 0; j < NumberOfCards(); j++) {
      if(IsBetter(i, j)) cnt++;
    }
    PutInt(0, cnt);
  }
  Send(0);
  if (MyNodeId() != 0) return 0;

  int idx = 0;
  for (int k = 0; k < NumberOfNodes(); k++) {
    Receive(k);
    int len = GetInt(k);
    for(int i = 0; i < len; i++)
      degrees[idx++] = GetInt(k);
  }

  sort(degrees, degrees + NumberOfCards());

  idx = 0;
  int cnt = 1, outDeg = degrees[idx++];
  while(idx < NumberOfCards() && outDeg > cnt * (cnt - 1) / 2) {
    cnt++; outDeg += degrees[idx++];
  }

  if(idx == NumberOfCards()) printf("IMPOSSIBLE\n");
  else printf("%d\n", (int) NumberOfCards() - cnt);
  return 0;
}
