#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int N;
string S[100005];

int c[100005], lastSeen[10], nextOccur[10][100005];

ll amt[10][100005], ans[100005];

ll powMod(ll a, ll b) {
  if (b == 0) return 1;
  ll x = powMod(a, b / 2);
  ll ret = (x * x) % MOD;
  if (b % 2 == 1) ret = (ret * a) % MOD;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  getline(cin, S[0], '\n');
  string strN;
  getline(cin, strN, '\n');
  N = stoi(strN);
  for (int i = 0; i < N; i++) {
    string first, second;
    getline(cin, first, '-');
    char x;
    cin >> x;
    getline(cin, second, '\n');
    c[i] = stoi(first);
    S[i + 1] = second;
  }

  for (int i = 0; i < 10; i++) lastSeen[i] = N;
  for (int i = N; i >= 0; i--) {
    if (i < N) {
      lastSeen[c[i]] = i;
    }
    for (int j = 0; j < 10; j++) {
      nextOccur[j][i] = lastSeen[j];
    }
  }

  for (int i = N; i >= 0; i--) {
    for (int j = 0; j < 10; j++) {
      if (i == N) {
        amt[j][i] = 1ll;
        continue;
      }
      if (c[i] == j) {
        ll ct = 0;
        for (auto l : S[i + 1]) {
          ct = (ct + amt[l - '0'][i + 1]) % (MOD - 1);
        }
        amt[j][i] = ct;
      } else {
        amt[j][i] = amt[j][nextOccur[j][i]];
      }
    }
  }

  for (int i = N; i >= 0; i--) {
    ll ct = 0;
    ll digits = 0;

    for (int j = S[i].size() - 1; j >= 0; j--) {
      int l = S[i][j] - '0';
      int n = nextOccur[l][i];
      ll val = n != N ? ans[n + 1] : l;
      ct = (ct + (val * powMod(10, digits)) % MOD) % MOD;
      digits = (digits + amt[l][i]) % (MOD - 1);
    }
    ans[i] = ct;
  }
  cout << ans[0] % MOD << endl;
  return 0;
}
