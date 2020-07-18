#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M, P[3005], fp;
bool vis[3005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1, x; i <= N; i++) {
    // cin >> x;
    cin >> P[i];
    // P[x] = i;
  }
  cin >> M;

  vector<int> starts;
  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      starts.push_back(i);
      int x = P[i];
      while (x != i) {
        vis[x] = true;
        x = P[x];
        fp++;
      }
    }
  }

  vector<ii> ANS;
  if (fp <= M) {
    for (int i = 1; i <= M - fp; i++) {
      ANS.push_back(ii(1, starts[i]));
    }
  } else {
    int need = fp - M, i = 1;
    while (need > 0 && i <= N) {
      if (P[i] == i) {
        i++;
        continue;
      }
      int small = INT_MAX;
      int x = P[i];
      while (x != i) {
        if (x < small) small = x;
        x = P[x];
      }
      ANS.push_back(ii(i, small));
      int temp = P[small];
      P[small] = P[i];
      P[i] = temp;
      need--;
    }
  }

  cout << ANS.size() << endl;
  for (int i = 0; i < ANS.size(); i++)
    cout << ANS[i].first << " " << ANS[i].second
         << (i == ANS.size() - 1 ? "\n" : " ");
  return 0;
}
