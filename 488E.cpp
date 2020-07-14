#include <bits/stdc++.h>
using namespace std;
long long N;
vector<int> ans;

bool isPrime[100005], vis[100005];

// inverse of a modulo b, between 1 and b inclusive
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;

  for (int i = 2; i < 100005; i++) {
    if (!vis[i]) {
      isPrime[i] = true;
      for (int j = i; j < 100005; j += i) {
        vis[j] = true;
      }
    }
  }
  if (N == 1) {
    cout << "YES" << endl;
    cout << 1 << endl;
    return 0;
  }

  if (N == 4) {
    cout << "YES" << endl;
    cout << 1 << "\n" << 3 << "\n" << 2 << "\n" << 4 << "\n";
    return 0;
  }

  if (!isPrime[N]) {
    cout << "NO" << endl;
    return 0;
  }

  ans.push_back(1);
  for (long long i = 2; i <= N - 1; i++) {
    ans.push_back((inv(i - 1, N) * i) % N);
  }
  ans.push_back(N);
  cout << "YES" << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}
