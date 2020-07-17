#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<string> arr;

map<char, int> m = {{'S', 0}, {'E', 1}, {'T', 2}};
vector<char> v{'S', 'E', 'T'};
unordered_map<string, int> m2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    arr.push_back(s);
    m2[s] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      string a = "";
      for (int s = 0; s < K; s++) {
        char b = arr[i][s], c = arr[j][s];
        if (b == c) {
          a += b;
        } else {
          a += v[3 - m[b] - m[c]];
        }
      }
      if (m2.count(a) > 0) {
        ans++;
      }
    }
  }
  cout << ans / 3 << endl;

  return 0;
}
