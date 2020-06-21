#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, K, r[1005];
bool used[1005];
vector<pair<int, ii>> pc;
vector<pair<int, int>> tables;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1, c, p; i <= N; i++) {
    cin >> c >> p;
    pc.push_back(make_pair(-p, ii(i, c)));
  }
  cin >> K;
  for (int i = 1, r; i <= K; i++) {
    cin >> r;
    tables.push_back(ii(r, i));
  }

  int num = 0, amt = 0;
  vector<ii> ANS;
  sort(pc.begin(), pc.end());
  sort(tables.begin(), tables.end());
  for (int i = 0; i < (int)pc.size(); i++) {
    int idx = pc[i].second.first, c = pc[i].second.second, p = -pc[i].first;
    for (int j = 0; j < K; j++) {
      if (tables[j].first >= c && !used[j]) {
        used[j] = true;
        num++;
        amt += p;
        ANS.push_back(ii(idx, tables[j].second));
        break;
      }
    }
  }
  cout << num << " " << amt << endl;
  for (auto x : ANS) cout << x.first << " " << x.second << endl;

  return 0;
}
