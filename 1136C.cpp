#include <bits/stdc++.h>
using namespace std;
int N, M;
map<int, vector<int>> a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x;
      cin >> x;
      a[i + j].push_back(x);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x;
      cin >> x;
      b[i + j].push_back(x);
    }
  }
  for (int i = 0; i <= (N - 1 + M - 1); i++) {
    vector<int> x = a[i], y = b[i];
    if (x.size() != y.size()) {
      cout << "NO" << endl;
      return 0;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < x.size(); i++) {
      if (x[i] != y[i]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;

  return 0;
}
