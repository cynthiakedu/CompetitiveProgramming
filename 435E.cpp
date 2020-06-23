#include <bits/stdc++.h>
using namespace std;
int N, M, arrNorm[1005][1005], arrInv[1005][1005];
int filled[1005][1005];

bool fill(int arr[1005][1005], int n, int m) {
  vector<int> forRow(5, -1);
  int row[1005][5];
  memset(row, -1, sizeof(row[0][0]) * 1005 * 5);

  // check
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = arr[i][j];
      if (!x) continue;
      if (row[i][x] != -1 && (row[i][x] != j % 2)) return false;
      row[i][x] = j % 2;

      if (forRow[x] != -1 && (forRow[x] != i % 2)) return false;
      forRow[x] = i % 2;
    }
  }

  // Assign row
  vector<int> oddRows, evenRows, noRows;
  for (int j = 1; j <= 4; j++) {
    if (forRow[j] == 1) {
      oddRows.push_back(j);
    } else if (forRow[j] == 0) {
      evenRows.push_back(j);
    } else {
      noRows.push_back(j);
    }
  }
  if (oddRows.size() > 2 || evenRows.size() > 2) return false;
  for (auto x : noRows) {
    if (oddRows.size() < 2) {
      oddRows.push_back(x);
    } else {
      evenRows.push_back(x);
    }
  }

  // Fill
  for (int i = 1; i <= n; i++) {
    int pattern[2] = {-1, -1};
    vector<int> chooseFrom = i % 2 == 1 ? oddRows : evenRows;
    for (auto x : chooseFrom) {
      if (row[i][x] != -1) {
        if (pattern[row[i][x]] != -1 && pattern[row[i][x]] != x) {
          return false;
        } else {
          pattern[row[i][x]] = x;
        }
      }
    }

    for (auto x : chooseFrom) {
      if (row[i][x] == -1) {
        if (pattern[0] == -1) {
          pattern[0] = x;
        } else {
          pattern[1] = x;
        }
      }
    }

    for (int j = 1; j <= m; j++) {
      filled[i][j] = (j % 2 ? pattern[1] : pattern[0]);
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      char x;
      cin >> x;
      arrNorm[i][j] = x - '0';
      arrInv[j][i] = x - '0';
    }
  }

  bool canRow = fill(arrNorm, N, M);
  if (canRow) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        cout << filled[i][j];
      }
      cout << endl;
    }
    return 0;
  }

  bool canCol = fill(arrInv, M, N);
  if (canCol) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        cout << filled[j][i];
      }
      cout << endl;
    }
    return 0;
  }

  cout << 0 << endl;
  return 0;
}

// 5 3
// 100
// 001
// 100
// 020
// 100

// 2 2
// 12
// 34

// 2 2
// 1 0
// 0 1

// 1 1
// 0