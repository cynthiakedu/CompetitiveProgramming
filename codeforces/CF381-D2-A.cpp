#include <bits/stdc++.h>
using namespace std;
int N, arr[1005], l, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  l = 1;
  r = N;
  for (int i = 1; i <= N; i++)
    cin >> arr[i];
  int s = 0, d = 0;
  for (int i = 0; i < N; i++) {
    if (arr[l] > arr[r]) {
      if (i % 2 == 0) {
        s += arr[l];
      } else {
        d += arr[l];
      }
      l++;
    } else {
      if (i % 2 == 0) {
        s += arr[r];
      } else {
        d += arr[r];
      }
      r--;
    }
  }
  cout << s << " " << d << endl;

  return 0;
}
