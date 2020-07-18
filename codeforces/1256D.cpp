#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long Q, N, K;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> Q;
  for (int q = 0; q < Q; q++) {
    cin >> N >> K;
    cin >> s;
    string ans = "";
    int l = 0;
    ll ct = 0;
    for (int i = 0; i < s.size(); i++) {
      if (ct > K) {
        for (int j = 0; j < ct - K; j++) {
          ans += '1';
          l++;
        }
        ct = K;
      }
      if (s[i] == '1') {
        ct++;
      } else {
        ans += '0';
        K -= ct;
        l++;
      }
    }
    for (int i = l; i < l + ct; i++) {
      ans += '1';
    }
    for (int i = l + ct; i < s.size(); i++) {
      ans += s[i];
    }
    cout << ans << endl;
  }

  return 0;
}