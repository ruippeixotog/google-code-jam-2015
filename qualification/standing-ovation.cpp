#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int smax; cin >> smax;
    int friends = 0, standing = 0;

    for(int i = 0; i <= smax; i++) {
      char digit; cin >> digit;
      int si = (int)(digit - '0');

      if(i > standing) { friends += i - standing; standing = i; }
      standing += si;
    }

    cout << "Case #" << tc << ": " << friends << endl;
  }
  return 0;
}
