#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int N, M, a[100005];
ll cum[100005];
vector<ii> Q[105];
ll MOD = 1000000007;
ll C[100105][105];

int main(int argc, const char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int n = 1; n < 100105; n++)
    for (int k = 0; k < 105; k++) {
      if (k == 0 || k == n) {
        C[n][k] = 1;
      } else {
        C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
      }
    }

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> a[i];
  for (int i = 0, l, r, k; i < M; i++) {
    cin >> l >> r >> k;
    Q[k].push_back(ii(l, r));
  }
  for (int i = 100; i >= 0; i--) {
    ll ends[100005] = {0}, ones[100005] = {0};
    for (auto p : Q[i]) {
      ends[p.first] += 1;
      ends[p.second + 1] -= 1;
      //   if (i != 0) {
      //     ones[p.second + 1] -= p.second + 1 - p.first;
      //   }
    }
    // cout << "Result ends i " << i << endl;
    // for (int t = 0; t < N + 1; t++) {
    //   cout << ends[t] << " ";
    // }
    // cout << endl;
    int s = 0;
    for (int j = 0; j < N + 1; j++) {
      s += ends[j];
      ones[j] += s;
    }
    if (i != 0) {
      for (int j = 1; j < N + 1; j++) {
        ones[j] += ones[j - 1];
      }
    }

    // cout << "Result ones i " << i << endl;
    // for (int t = 0; t < N + 1; t++) {
    //   cout << ones[t] << " ";
    // }
    // cout << endl;

    // cout << "Result i before" << i << endl;
    // for (int t = 0; t < N + 1; t++) {
    //   cout << cum[t] << " ";
    // }
    // cout << endl;

    if (i != 0) {
      for (int j = i; j <= 100; j++) {
        for (auto p : Q[j]) {
          cum[p.second + 1] -= C[p.second - p.first + j - i + 1][j - i + 1];
        }
      }
    }

    // cout << "Result i before" << i << endl;
    // for (int t = 0; t < N + 1; t++) {
    //   cout << cum[t] << " ";
    // }
    // cout << endl;

    if (i != 0) {
      for (int j = 1; j < N + 1; j++) {
        cum[j] = cum[j] + cum[j - 1];
        cum[j] %= MOD;
      }
    }

    for (int j = 1; j < N + 1; j++) {
      cum[j] += ones[j];
      cum[j] %= MOD;
    }
    // }

    // cout << "Result i " << i << endl;
    // for (int t = 0; t < N + 1; t++) {
    //   cout << cum[t] << " ";
    // }
    // cout << endl;
  }
  for (int t = 1; t <= N; t++) {
    cout << (cum[t] + a[t] + MOD) % MOD << (t == N ? "\n" : " ");
  }
  //   cout << ((cum[18] + a[18] + MOD) % MOD) << endl;
  return 0;
}
