#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, d[(1 << 16) + 5], s[(1 << 16) + 5];
queue<int> q;
vector<ii> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> d[i] >> s[i];
    if (d[i] == 1) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    if (d[x] == 1) {
      int y = s[x];
      ans.push_back(ii(x, y));
      d[y] -= 1;
      s[y] = s[y] ^ x;
      if (d[y] == 1) {
        q.push(y);
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;

  return 0;
}
