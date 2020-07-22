#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
vector<ii> cards;
map<char, int> G = {{'R', 0}, {'G', 1}, {'B', 2}, {'Y', 3}, {'W', 4}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    char g;
    int x;
    cin >> g >> x;
    cards.push_back(ii(G[g], x - 1));
  }

  int ans = 10;
  for (int i = 0; i < (1 << 5); i++) {
    for (int j = 0; j < (1 << 5); j++) {
      bool can = true;
      int ct = 0;
      set<int> colors[5];
      set<int> numbers[5];
      for (auto c : cards) {
        if (!(i & (1 << c.second))) {
          colors[c.first].insert(c.second);
        }
        if (!(j & (1 << c.first))) {
          numbers[c.second].insert(c.first);
        }
      }
      for (int k = 0; k < 5; k++) {
        if (colors[k].size() > 1) {
          can = false;
        }
        if (numbers[k].size() > 1) {
          can = false;
        }
        if (i & (1 << k)) ct++;
        if (j & (1 << k)) ct++;
      }
      if (can) {
        ans = min(ans, ct);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
