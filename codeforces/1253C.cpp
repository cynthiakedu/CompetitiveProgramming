#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
ll arr[200005];
ll cum[200005];

ll ans[200005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  sort(arr + 1, arr + N + 1);
  for (int i = 1; i <= N; i++) cum[i] = cum[i - 1] + arr[i];

  for (int i = 1; i <= N; i++) {
    if (i <= M) {
      ans[i] = cum[i];
    } else {
      ans[i] = cum[i] + ans[i - M];
    }
    cout << ans[i] << (i == N ? "\n" : " ");
    ;
  }

  return 0;
}
