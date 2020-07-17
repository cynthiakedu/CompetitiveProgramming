#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, K, arr[200005];
vector<ii> v;
int s[200005];
int n[200005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    v.push_back(ii(arr[i], i));
  }
  sort(v.begin(), v.end());
  int ct = 0, idx = 0;
  while (idx < v.size()) {
    int j = idx, c = 0;
    while (j < v.size() && v[j].first == v[idx].first) {
      s[v[j].second] = ct;
      c++;
      j++;
    }
    ct += c;
    idx = j;
  }
  for (int i = 1; i <= K; i++) {
    int x, y;
    cin >> x >> y;
    if (arr[x] > arr[y]) {
      n[x]++;
    } else if (arr[y] > arr[x]) {
      n[y]++;
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << s[i] - n[i] << (i == N ? "\n" : " ");
  }

  return 0;
}
