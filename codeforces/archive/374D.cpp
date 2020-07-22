// 374D
// 6/11/20

#include <bits/stdc++.h>
using namespace std;
int N, M, exist[1000005], cum[1000005];
vector<int> in, val, numHitAfter;
int ct = 0;

int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0, x; i < M; i++) {
    cin >> x;
    exist[x] = 1;
  }

  int s = 0;
  for (int i = 1; i < 1000005; i++) {
    s += exist[i];
    cum[i] = s;
  }

  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    ct = t == -1 ? ct - cum[ct] : ct + 1;
    in.push_back(t);
    val.push_back(ct);
  }

  numHitAfter.resize(val.size());
  int amt = 0;
  for (int i = (int)val.size() - 1; i >= 0; i--) {
    amt += (in[i] == -1);
    numHitAfter[i] = amt;
  }

  vector<int> memo(N + 1, INT_MAX);
  memo[0] = 0;
  for (int i = 1; i < N + 1; i++) {
    int idx = cum[i];
    if (exist[i])
      memo[i] = 1;
    else if (idx != 0 && memo[i - idx] < INT_MAX) {
      memo[i] = memo[i - idx] + 1;
    }
  }

  vector<int> ANS;
  for (int i = 0; i < in.size(); i++) {
    if (in[i] != -1 && memo[val[i]] > numHitAfter[i]) {
      ANS.push_back(in[i]);
    }
  }

  if (ANS.size() == 0) {
    cout << "Poor stack!" << endl;
  } else {
    for (auto x : ANS) cout << x;
    cout << endl;
  }

  return 0;
}
