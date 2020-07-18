#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int a, b;
vector<ii> aPairs, bPairs;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b;
  for (int i = 1; i < a; i++)
    for (int j = 1; j < a; j++) {
      if (i * i + j * j == a * a) {
        aPairs.push_back(ii(i, j));
      }
    }

  for (int i = 1; i < b; i++)
    for (int j = 1; j < b; j++) {
      if (i * i + j * j == b * b) {
        bPairs.push_back(ii(i, j));
      }
    }

  for (auto p1 : aPairs)
    for (auto p2 : bPairs) {
      int a = p1.first, b = p1.second;
      int c = p2.first, d = p2.second;
      if (p1.second != p2.second && a * c == b * d) {
        cout << "YES" << endl;
        cout << "0 0" << endl;
        cout << -p1.first << " " << -p1.second << endl;
        cout << p2.first << " " << -p2.second << endl;
        return 0;
      }
    }
  cout << "NO" << endl;

  return 0;
}
