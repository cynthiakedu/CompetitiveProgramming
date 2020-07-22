#include <bits/stdc++.h>
using namespace std;
typedef ll;
int N;
int arr[100005];
int mn = INT_MAX, idx = 0;
int ans[100005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    if (x < 0) {
      x = -x - 1;
    }
    arr[i] = x;
    if (arr[i] != arr[i] < mn) {
      mn = arr[i];
      idx = i;
    }
  }
  if (N == 1) {
    cout << max(arr[0], -arr[0] - 1) << endl;
  } else if (N == 2) {
    vector<int> a{arr[0], -arr[0] - 1};
    vector<int> b{arr[1], -arr[1] - 1};
    int ans = INT_MIN;
    vector<int> v;
    for (int i = 0; i < 1; i++) {
      for (int j = 0; j < 1; j++) {
        vector<int> v1 = {a[i], b[j]};
        if (a[i] * b[j] > ans) {
          ans = a[i] * b[j];
          v = v1;
        }
      }
    }
  } else {
    for (int i = 0; i < N; i++) {
      if (i == idx) }
  }

  return 0;
}
