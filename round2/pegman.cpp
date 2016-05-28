#include <iostream>

#define MAXR 100
#define MAXC 100
#define INF 1e6

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int r, c;
int grid[MAXR][MAXC];
bool visited[MAXR][MAXC];

bool isValid(int i, int j) {
  return i >= 0 && j >= 0 && i < r && j < c;
}

void follow(int i, int j, int& iNext, int& jNext) {
  iNext = i; jNext = j; int d = grid[i][j];
  if(d < 0) return;

  do {
    iNext += dr[d]; jNext += dc[d];
  } while(isValid(iNext, jNext) && grid[iNext][jNext] < 0);
}

int process(int i0, int j0) {
  if(grid[i0][j0] < 0 || visited[i0][j0]) return false;

  int cnt = 0;

  int i, j; bool found = false;
  for(int d = 0; d < 4; d++) {
    follow(i0, j0, i, j);
    if(isValid(i, j)) { found = true; break; }

    grid[i0][j0] = (grid[i0][j0] + 1) % 4;
    cnt = 1;
  }

  if(!found) return INF;

  i = i0, j = j0;
  while(isValid(i, j) && !visited[i][j]) {
    visited[i][j] = true;
    follow(i, j, i, j);
  }

  if(!isValid(i, j)) cnt++;
  return cnt;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> r >> c;

    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++) {
        char ch; cin >> ch;
        switch(ch) {
          case '.': grid[i][j] = -1; break;
          case '^': grid[i][j] = 0; break;
          case '>': grid[i][j] = 1; break;
          case 'v': grid[i][j] = 2; break;
          case '<': grid[i][j] = 3; break;
        }
      }

    memset(visited, 0, sizeof(visited));

    int sum = 0;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        sum += process(i, j);
      }
    }

    cout << "Case #" << tc << ": ";
    if(sum >= INF) cout << "IMPOSSIBLE" << endl;
    else cout << sum << endl;
  }
  return 0;
}
