#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int N, Q, arr[(1 << 20) + 5], queries[25] = {0};  // Normal, inversion
ll ct[25][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < 1 << N; i++) cin >> arr[i];
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 1 << N; j += 1 << i) {
      vector<ii> s;
      for (int k = 0; k < 1 << (i - 1); k++) {
        s.push_back(ii(arr[j + k], 1));
        s.push_back(ii(arr[j + (1 << (i - 1)) + k], 2));
      }
      sort(s.begin(), s.end());
      ll last1 = 0, curr1 = 0, last2 = 0, curr2 = 0, idx = 0;
      while (idx < s.size()) {
        ii b = s[idx];
        while (idx < s.size() && s[idx].first == b.first) {
          if (s[idx].second == 2) {
            curr2++;
            ct[i][0] += last1;
          } else {
            curr1++;
            ct[i][1] += last2;
          }
          idx++;
        }
        last1 += curr1;
        curr1 = 0;
        last2 += curr2;
        curr2 = 0;
      }
    }
  }

  cin >> Q;
  for (int i = 0, q; i < Q; i++) {
    cin >> q;
    queries[q]++;
    ll s = 0;
    ll totalInv = 0;
    for (int j = N; j >= 1; j--) {
      s += queries[j];
      if (s % 2 == 0) {
        totalInv += ct[j][1];
      } else {
        totalInv += ct[j][0];
      }
    }
    cout << totalInv << "\n";
  }
  return 0;
}
