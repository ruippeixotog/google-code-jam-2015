#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <utility>

#define MAXX 6
#define MAXR 20
#define MAXC 20

using namespace std;

typedef pair<int, int> Block;
typedef set<Block>::iterator sbiterator;
typedef vector<Block> Omino;
typedef set<Omino>::iterator soiterator;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

set<Omino> ominoes[MAXX + 1];

int x, r, c;
bool board[MAXR][MAXC];
bool visited[MAXR][MAXC];

bool putBlock(const Block& b, int row, int col) {
  row += b.first; col += b.second; 
  if(row < 0 || row >= r || col < 0 || col >= c || board[row][col])
    return false;

  board[row][col] = true;
  return true;
}

void removeBlock(const Block& b, int row, int col) {
  board[row + b.first][col + b.second] = false;
}

bool putOmino(const Omino& om, int row, int col) {
  for(int i = 0; i < om.size(); i++) {
    if(!putBlock(om[i], row, col)) {
      for(int j = 0; j < i; j++) {
        removeBlock(om[j], row, col);
      }
      return false;
    }
  }
  return true;
}

void removeOmino(const Omino& om, int row, int col) {
  for(int i = 0; i < om.size(); i++) {
    removeBlock(om[i], row, col);
  }
}

void normalizeOmino(Omino& om) {
  Block pivot = om[0];
  for(int i = 0; i < om.size(); i++) {
    om[i].first -= pivot.first;
    om[i].second -= pivot.second;
  }
}

Omino rotate90Omino(const Omino& om) {
  Omino rotated;
  for(int i = 0; i < om.size(); i++) {
    rotated.push_back(make_pair(om[i].second, om[i].first)); 
  }
  normalizeOmino(rotated);
  return rotated;
}

void genOminoes(int x, set<Block>& curr, int left) {
  if(left == 0) {
    Omino om(curr.begin(), curr.end());
    normalizeOmino(om);
    ominoes[x].insert(om);
    return;
  }

  for(sbiterator it = curr.begin(); it != curr.end(); it++) {
    for(int d = 0; d < 4; d++) {
      Block b = make_pair(it->first + dr[d], it->second + dc[d]);
      if(!curr.count(b)) {
        curr.insert(b);
        genOminoes(x, curr, left - 1);
        curr.erase(b);
      }
    }
  }
}

void genAllOminoes() {
  set<Block> curr;
  ominoes[1].insert(vector<Block> { make_pair(0, 0) });
  curr.insert(make_pair(0, 0));

  for(int x = 2; x < 7; x++) {
    genOminoes(x, curr, x - 1);
  }
}

int emptyAreaSize(int row, int col) {
  if(row < 0 || row >= r || col < 0 || col >= c ||
      board[row][col] || visited[row][col]) {
    return 0;
  }

  visited[row][col] = true;
  int size = 1;
  for(int d = 0; d < 4; d++) {
    size += emptyAreaSize(row + dr[d], col + dc[d]);
  }
  return size;
}

bool canFillEmptySpaces() {
  memset(visited, false, sizeof(visited));
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(!board[i][j] && emptyAreaSize(i, j) % x != 0)
        return false;
    }
  }
  return true;
}

// play after the mandatory Omino is chosen by Richard
bool play2(const Omino& om) {
  Omino rotated = rotate90Omino(om);

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(putOmino(om, i, j)) {
        bool res = canFillEmptySpaces();
        removeOmino(om, i, j);
        if(res) return true;
      }
      if(putOmino(rotated, i, j)) {
        bool res = canFillEmptySpaces();
        removeOmino(rotated, i, j);
        if(res) return true;
      }
    }
  }
  return false;
}

bool play() {
  memset(board, false, sizeof(board));
  for(soiterator it = ominoes[x].begin(); it != ominoes[x].end(); it++) {
    if(!play2(*it)) return false;
  }
  return true;
}

int main() {
  genAllOminoes();

  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cin >> x >> r >> c;

    string winner = x < 7 && r * c % x == 0 && play() ? "GABRIEL" : "RICHARD";
    cout << "Case #" << tc << ": " << winner << endl;
  }
  return 0;
}
