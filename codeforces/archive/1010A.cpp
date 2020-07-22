#include <bits/stdc++.h>
using namespace std;
int N;
double M;
int a[1005], b[1005];
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  for (int i = 1; i <= N; i++)
    cin >> b[i];
  v.push_back(a[1]);
  for (int i = 2; i <= N; i++) {
    v.push_back(b[i]);
    v.push_back(a[i]);
  }
  v.push_back(b[1]);

  double x = 0;
  double total = M;
  for (int i = v.size() - 1; i >= 0; i--) {
    x = (total) / (v[i] - 1);
    if (v[i] == 1) {
      cout << -1 << endl;
      return 0;
    }
    total += x;
  }
  cout << setprecision(15) << total - M << endl;
  return 0;
}
