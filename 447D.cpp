#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, K, P;
ll arr[1005][1005];
ll rowRes[1000005], colRes[1000005];
ll rowCum[1000005], colCum[1000005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K >> P;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> arr[i][j];
    }
  }

  priority_queue<int> rowSums, colSums;
  for (int i = 1; i <= N; i++) {
    ll s = 0;
    for (int j = 1; j <= M; j++) {
      s += arr[i][j];
    }
    rowSums.push(s);
  }
  for (int j = 1; j <= M; j++) {
    ll s = 0;
    for (int i = 1; i <= N; i++) {
      s += arr[i][j];
    }
    colSums.push(s);
  }

  for (int i = 1; i <= K; i++) {
    ll sRow = rowSums.top();
    rowSums.pop();
    rowRes[i] = sRow;
    sRow -= (ll)M * (ll)P;
    rowSums.push(sRow);

    ll sCol = colSums.top();
    colSums.pop();
    colRes[i] = sCol;
    sCol -= (ll)N * (ll)P;
    colSums.push(sCol);
  }
  for (int i = 1; i <= K; i++) {
    rowCum[i] = rowCum[i - 1] + rowRes[i];
    colCum[i] = colCum[i - 1] + colRes[i];
  }

  ll ANS = LLONG_MIN;
  for (int i = 0; i <= K; i++) {
    int a = i, b = K - i;
    ANS = max(ANS, rowCum[a] + colCum[b] - (ll)b * (ll)a * (ll)P);
  }
  cout << ANS << endl;

  return 0;
}
