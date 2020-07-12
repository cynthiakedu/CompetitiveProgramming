#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int N, arr[1000005], cumIndiv[1000005];
map<int, int> freq;
set<ii> s;

class FenwickTree {
 private:
  vector<int> ft;

 public:
  FenwickTree(int n) { ft.assign(n + 3, 0); }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= (b & (-b))) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += (k & (-k))) {
      ft[k] += v;
    }
  }
};

FenwickTree ft(1000005);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    cumIndiv[i] = freq[arr[i]];
    freq[arr[i]] += 1;
  }
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    int need = freq[arr[i]] - cumIndiv[i];
    ll d = ft.rsq(need + 1, 1000001);
    ans += d;
    ft.adjust(cumIndiv[i] + 1, 1);
  }
  cout << ans << endl;

  return 0;
}
