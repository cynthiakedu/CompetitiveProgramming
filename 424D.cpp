#include <bits/stdc++.h>
using namespace std;
int n, m, t, tp, tu, td;
int arr[305][305];
int rowCumRight[305][305], rowCumLeft[305][305];
int colCumDown[305][305], colCumUp[305][305];
int ansAmt = INT_MAX;
vector<int> ans;

void initCum() {
  for (int i = 1; i <= n; i++) {
    int sR = 0, sL = 0;
    for (int j = 1; j < m; j++) {
      int a = arr[i][j], b = arr[i][j + 1];
      sR += b == a ? tp : (b > a ? tu : td);
      sL += a == b ? tp : (a > b ? tu : td);
      rowCumRight[i][j] = sR;
      rowCumLeft[i][j] = sL;
    }
  }
  for (int j = 1; j <= m; j++) {
    int sD = 0, sU = 0;
    for (int i = 1; i < n; i++) {
      int a = arr[i][j], b = arr[i + 1][j];
      sD += b == a ? tp : (b > a ? tu : td);
      sU += a == b ? tp : (a > b ? tu : td);
      colCumDown[i][j] = sD;
      colCumUp[i][j] = sU;
    }
  }
}

void printGrid(int x[305][305]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << x[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> t;
  cin >> tp >> tu >> td;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> arr[i][j];

  initCum();
  //   cout << "rowCumRight" << endl;
  //   printGrid(rowCumRight);
  //   cout << "rowCumLeft" << endl;
  //   printGrid(rowCumLeft);
  //   cout << "colCumDown" << endl;
  //   printGrid(colCumDown);
  //   cout << "colCumUp" << endl;
  //   printGrid(colCumUp);

  for (int i = 1; i <= n; i++) {
    for (int j = i + 2; j <= n; j++) {
      set<int> pos;
      map<int, int> toIdx;
      for (int k = 3; k <= m; k++) {
        int x = (colCumUp[j - 1][k - 2] - colCumUp[i - 1][k - 2]) -
                (rowCumRight[i][k - 3] + rowCumLeft[j][k - 3]);
        pos.insert(x);
        toIdx[x] = k - 2;
        int y = (colCumDown[j - 1][k] - colCumDown[i - 1][k]) +
                (rowCumRight[i][k - 1] + rowCumLeft[j][k - 1]);
        set<int>::iterator it1 = pos.lower_bound(t - y);
        if (it1 != pos.end()) {
          int val1 = *it1;
          if (abs(val1 + y - t) <= ansAmt) {
            ansAmt = abs(val1 + y - t);
            ans = vector<int>{i, toIdx[val1], j, k};
          }
        }
        if (it1 == pos.begin()) continue;
        set<int>::iterator it2 = prev(it1);
        if (it2 != pos.end()) {
          int val2 = *it2;
          if (abs(val2 + y - t) <= ansAmt) {
            ansAmt = abs(val2 + y - t);
            ans = vector<int>{i, toIdx[val2], j, k};
          }
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) cout << ans[i] << (i == 3 ? "\n" : " ");

  return 0;
}