#include <bits/stdc++.h>
using namespace std;
int n, m, k, arr[105][105];

int check(int c[105], int ctC, int secRow) {
  int ans = INT_MAX;
  if (ctC > 10) return ans;

  for (int i = 0; i < (1 << ctC); i++) {
    int ct = 0;
    for (int r = 2; r <= n; r++) {
      if (r != secRow) {
        int same = 0;
        for (int j = 1; j <= m; j++) {
          int row1El =
              c[j] >= 0 && (i & (1 << c[j])) ? 1 - arr[1][j] : arr[1][j];
          if (row1El == arr[r][j]) same++;
        }
        ct += min(same, m - same);
      }
    }
    ans = min(ctC + ct, ans);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }

  if (n == 1 || m == 1) {
    cout << 0 << endl;
    return 0;
  }
  int ans = INT_MAX;
  for (int secRow = 2; secRow <= min(15, n); secRow++) {
    int ctA = 0, ctB = 0;
    int a[105], b[105];
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));

    for (int j = 1; j <= m; j++) {
      if ((arr[1][j] ^ arr[secRow][j]) == 1) {
        a[j] = ctA;
        ctA++;
      } else {
        b[j] = ctB;
        ctB++;
      }
    }

    ans = min(check(a, ctA, secRow), check(b, ctB, secRow));
  }

  cout << (ans > k ? -1 : ans) << "\n";

  return 0;
}
