#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M;
vector<ii> C;
int ctA = 0, ctB = 0;
int sA = INT_MIN, sB = INT_MIN, s = INT_MIN;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    C.push_back(ii(x, 0));
    ctA++;
  }
  cin >> M;
  for (int i = 0, x; i < M; i++) {
    cin >> x;
    C.push_back(ii(x, 1));
    ctB++;
  }
  sA = 3 * ctA;
  sB = 3 * ctB;
  s = sA - sB;
  sort(C.begin(), C.end());

  int idx = 0;
  int sA1 = sA, sB1 = sB;
  while (idx != C.size()) {
    int j = idx;
    while (j < C.size() && C[j].first == C[idx].first) {
      if (C[j].second == 0)
        sA1--;
      else
        sB1--;
      j++;
    }
    if (sA1 - sB1 > s) {
      s = sA1 - sB1;
      sA = sA1;
      sB = sB1;
    }

    if (sA1 - sB1 == s && sA1 > sA) {
      sA = sA1;
      sB = sB1;
    }
    idx = j;
  }
  cout << sA << ":" << sB << endl;

  return 0;
}
