#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M;
int a[100005], b[100005], c[100005], d[100005];
int k[100005];
int ans[100005];
vector<ii> S;
set<pair<ii, int>> actors;  //(right, -count), id

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> c[i] >> d[i] >> k[i];
    S.push_back(ii(c[i], i));
  }
  for (int i = 0; i < N; i++) {
    S.push_back(ii(a[i], M + i));
  }
  sort(S.begin(), S.end());

  for (int i = 0; i < S.size(); i++) {
    int pos = S[i].first, id = S[i].second;
    if (id >= M) {  // part
      id -= M;
      int r = b[id];
      set<pair<ii, int>>::iterator it =
          actors.lower_bound(make_pair(ii(r, INT_MIN), INT_MIN));
      if (it == actors.end()) {
        cout << "NO" << endl;
        return 0;
      }
      pair<ii, int> p = *it;
      ans[id] = p.second + 1;
      actors.erase(it);
      if (p.first.second < -1) {
        actors.insert(
            make_pair(ii(p.first.first, p.first.second + 1), p.second));
      }
    } else {
      actors.insert(make_pair(ii(d[id], -(k[id])), id));
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < N; i++) {
    cout << ans[i] << (i == (N - 1) ? "\n" : " ");
  }

  return 0;
}
