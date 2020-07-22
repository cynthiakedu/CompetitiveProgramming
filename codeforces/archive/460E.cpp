#include <bits/stdc++.h>
using namespace std;

int ansAmt;
struct P {
  int x, y;
};

P ans[10], arr[10];

bool comp(P a, P b) { return a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y; }

int dist(P a, P b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
vector<P> points;

int N, R;

void dfs(int x, int pos, int v) {
  if (x == N) {
    if (v <= ansAmt) return;
    ansAmt = v;
    for (int i = 0; i < N; i++) ans[i] = arr[i];
    return;
  }
  for (int i = pos; i < min((int)points.size(), 18); i++) {
    arr[x] = points[i];
    int v1 = 0;
    for (int j = 0; j < x; j++) v1 += dist(points[i], arr[j]);
    dfs(x + 1, i, v + v1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cin >> N >> R;
  R = 30;
  int ct = 0, ct1 = 0;

  for (int i = -R; i <= R; i++) {
    for (int j = -R; j <= R; j++) {
      if (i * i + j * j <= R * R) {
        ct1++;
        points.push_back({i, j});
        if (i * i + j * j >= (R - 1) * (R - 1)) {
          ct++;
        }
      }
    }
  }
  cout << "ct " << ct1 << " " << ct << endl;
  //   sort(points.begin(), points.end(), comp);
  //   dfs(0, 0, 0);

  //   cout << ansAmt << endl;

  //   for (int i = 0; i < N; i++) {
  //     cout << ans[i].x << " " << ans[i].y << endl;
  //   }
  return 0;
}
