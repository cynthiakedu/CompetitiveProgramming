#include <bits/stdc++.h>
using namespace std;
int N, q[200005];
int arr[2000005];
bool tf[2000005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N - 1; i++)
    cin >> q[i];

  arr[0] = 1;
  int mn = 1;
  for (int i = 1; i <= N - 1; i++) {
    arr[i] = arr[i - 1] + q[i];
    if (arr[i] > N + 2 || arr[i] < (-N - 2)) {
      cout << -1 << endl;
      return 0;
    }
    mn = min(mn, arr[i]);
  }
  int diff = 1 - mn;

  for (int i = 0; i <= N - 1; i++) {
    arr[i] += diff;
    if (tf[arr[i]]) {
      cout << -1 << endl;
      return 0;
    }
    tf[arr[i]] = true;
  }
  for (int i = 1; i <= N; i++) {
    if (!tf[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0; i <= N - 1; i++)
    cout << arr[i] << (i == N - 1 ? "\n" : " ");

  return 0;
}
