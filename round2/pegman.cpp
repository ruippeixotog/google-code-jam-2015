#include <iostream>
#include <utility>
#include <vector>

#define ll long long

#define MAXR 4
#define MAXC 4
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

int follow(int i, int j, int d);

int bf(int i, int j) {
  if(grid[i][j] < 0 || visited[i][j]) return 0;
  visited[i][j] = true;

  cerr << "visited " << i << "," << j << endl;

  int best = INF;
  for(int d = 0; d < 4; d++) {
    int res = follow(i, j, d);
    best = min(best, res + (d == grid[i][j] ? 0 : 1));
  }
  return best;
}

int follow(int i, int j, int d) {
  i += dr[d]; j += dc[d];
  if(!isValid(i, j)) return INF;
  if(grid[i][j] < 0) return follow(i, j, d);
  if(!visited[i][j]) {
    cerr << "follow to " << i << "," << j << " (" << d << ")" << endl;
    return bf(i, j);
  }
  return 0;
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
        sum += bf(i, j);
      }
    }

    cout << "Case #" << tc << ": ";
    if(sum >= INF) cout << "IMPOSSIBLE" << endl;
    else cout << sum << endl;
  }
  return 0;
}
