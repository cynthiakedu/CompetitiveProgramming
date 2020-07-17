#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
vector<ii> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;

  for (int i = 1; i <= (N / 2) * 3 + 1; i++) {
    ans.push_back(ii(i, 0));
    ans.push_back(ii(i, 3));
  }
  for (int i = 0; i <= 3; i++) {
    ans.push_back(ii(0, i));
    ans.push_back(ii((N / 2) * 3 + 2, i));
  }

  for (int i = 0; i < N / 2; i++) {
    int x = 3 * i + 2;
    ans.push_back(ii(x, 4));
    ans.push_back(ii(x + 1, 4));
    ans.push_back(ii(x, 2));
    ans.push_back(ii(x + 1, 2));
  }
  if (N % 2 == 1) {
    ans.push_back(ii((N / 2) * 3 + 2, 4));
    ans.push_back(ii((N / 2) * 3 + 3, 4));
    ans.push_back(ii((N / 2) * 3 + 3, 3));
  }
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}
