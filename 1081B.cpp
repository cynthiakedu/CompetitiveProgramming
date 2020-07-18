#include <bits/stdc++.h>
using namespace std;
int N, ans[100005];
vector<int> arr[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    arr[N - x].push_back(i);
  }
  int idx = 1;
  for (int i = 1; i <= N; i++) {
    if (arr[i].size() % i != 0) {
      cout << "Impossible" << endl;
      return 0;
    }
    int p = arr[i].size() / i;
    for (int j = 0; j < p; j++) {
      for (int k = 0; k < i; k++) {
        ans[arr[i][i * j + k]] = idx;
      }
      idx++;
    }
  }
  cout << "Possible" << endl;
  for (int i = 0; i < N; i++)
    cout << ans[i] << (i == N - 1 ? "\n" : " ");

  return 0;
}
