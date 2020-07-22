#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
bool vis[1000005];
vector<int> primes;
vector<int> ct;
ll ans = 0, pr = 1;

ll f(int x) {
  ll ret = 0;
  while (x > 1) {
    if (x % 2 == 1) {
      ret += 2;
      x = (x + 1) / 2;
    } else {
      ret += 1;
      x /= 2;
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 2; i <= 1000000; i++) {
    if (!vis[i]) {
      for (int j = i; j <= 1000000; j += i) {
        if (j == N)
          primes.push_back(i);
        vis[j] = true;
      }
    }
  }

  for (auto x : primes) {
    ll c = 0;
    while (N % x == 0) {
      N /= x;
      c++;
    }
    ans = max(ans, f(c));
    pr *= x;
  }

  cout << pr << " " << ans << endl;

  return 0;
}
