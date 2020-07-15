#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll x, y;
vector<ll> nums;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> x >> y;
  for (ll i = 1; i <= y; i++) {
    nums.push_back(i * x);
  }
  for (ll i = 1; i <= x; i++) {
    nums.push_back(i * y);
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    a = (a - 1) % nums.size();
    ll ele = nums[a];
    if (ele % x == 0 && ele % y == 0) {
      cout << "Both" << endl;
    } else if (ele % x == 0) {
      cout << "Vova" << endl;
    } else {
      cout << "Vanya" << endl;
    }
  }

  return 0;
}
