#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M;
vector<ii> V;

int main(int argc, const char *argv[]) {
  cin >> N >> M;
  for (int i = 0, x, y; i < M; i++) {
    cin >> x >> y;
    V.push_back(ii(x, y));
  }
  sort(V.begin(), V.end());

  vector<ii> currI;
  currI.push_back(ii(1, 1));
  int currRow = 0;
  for (int i = 0; i < V.size();) {
    ii p = V[i];
    vector<ii> newI;
    if (p.first > currRow + 1 && currI.size()) {
      int left = currI[0].first;
      currI.clear();
      currI.push_back(ii(left, N));
    }
    currRow = p.first;

    // cout << "On point i = " << i << "with coords " << p.first << " " <<
    // p.second
    //      << endl;
    // cout << "currI " << endl;
    // for (auto x : currI) cout << x.first << " " << x.second << endl;
    vector<ii> temp;
    int last = 0;
    while (i < V.size() && V[i].first == p.first) {
      temp.push_back(ii(last + 1, V[i].second - 1));
      last = V[i].second;
      i++;
    }
    temp.push_back(ii(last + 1, N));
    int j = 0;
    for (auto x : temp) {
      //   cout << "temp " << x.first << " " << x.second << endl;
      while (j < currI.size() && currI[j].second < x.first) j++;
      if (j < currI.size()) {
        int x1 = max(x.first, currI[j].first), x2 = x.second;
        if (x2 >= x1) {
          newI.push_back(ii(x1, x2));
        }
      }
    }
    // cout << "newI " << endl;
    // for (auto x : newI) cout << x.first << " " << x.second << endl;
    currI = newI;
  }
  bool poss = false;
  if (currI.size() > 0) {
    ii l = currI[currI.size() - 1];
    poss = (currRow < N && l.second <= N);
    poss = poss || (currRow == N && l.second == N);
  }
  if (poss) {
    cout << 2 * (N - 1) << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}