#include <algorithm>
#include <cstdio>

#include "almost_sorted.h"
#include "message.h"

#define MAXF 100000000
#define MAXK 1000000
#define MOD 1048576

using namespace std;

typedef long long ll;

ll ids[MAXF / 100 + 2 * MAXK];

int main() {
  int nodeBegin = (int) (MyNodeId() * NumberOfFiles() / NumberOfNodes());
  int nodeEnd = (int) ((MyNodeId() + 1) * NumberOfFiles() / NumberOfNodes());

  int sortBegin = max(0, (int) (nodeBegin - MaxDistance()));
  int sortEnd = (int) min(NumberOfFiles(), nodeEnd + MaxDistance());

  for(int i = sortBegin; i < sortEnd; i++)
    ids[i - sortBegin] = Identifier(i);

  sort(ids, ids + (sortEnd - sortBegin));

  int cks = 0;
  for(int i = nodeBegin; i < nodeEnd; i++)
    cks = (cks + i * (ids[i - sortBegin] % MOD)) % MOD;

  if(MyNodeId() != 0) {
    PutInt(0, cks);
    Send(0);

  } else {
    for(int k = 1; k < NumberOfNodes(); k++) {
      Receive(k);
      cks = (cks + GetInt(k)) % MOD;
    }
    printf("%d\n", cks);
  }
  return 0;
}
