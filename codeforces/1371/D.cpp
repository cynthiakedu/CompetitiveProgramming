#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int T, N, K;

void solve() {
  int grid[305][305] = {};
  int used[305] = {};
  cin >> N >> K;
  int num = K / N;
  int rem = K - N * num;
  for (int i = 0; i < N; i++) {
    int amt = i < rem ? num + 1 : num;
    vector<ii> v;
    for (int j = 0; j < N; j++) {
      v.push_back(ii(used[j], j));
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < amt; j++) {
      grid[i][v[j].second] = 1;
      used[v[j].second]++;
    }
  }
  int mxR = INT_MIN, mnR = INT_MAX, mxC = INT_MIN, mnC = INT_MAX;
  for (int i = 0; i < N; i++) {
    int sR = 0, sC = 0;
    for (int j = 0; j < N; j++) {
      if (grid[i][j])
        sR++;
      if (grid[j][i])
        sC++;
    }
    mxR = max(mxR, sR);
    mnR = min(mnR, sR);
    mxC = max(mxC, sC);
    mnC = min(mnC, sC);
  }
  cout << (mxR - mnR) * (mxR - mnR) + (mxC - mnC) * (mxC - mnC) << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }

  return 0;
}
