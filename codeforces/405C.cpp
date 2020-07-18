#include <bits/stdc++.h>
using namespace std;
int N, arr[1005][1005], Q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int ct = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
      if (i == j) ct += arr[i][j];
    }

  ct = ct % 2;

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;
    if (type == 3)
      cout << ct;
    else {
      int x;
      cin >> x;
      ct = (ct + 1) % 2;
    }
  }
  cout << endl;

  return 0;
}
