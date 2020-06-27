#include <bits/stdc++.h>
using namespace std;
int N;
vector<double> arr;
double p1 = 0, p0 = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    double x;
    cin >> x;
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end(), greater<>());

  for (auto x : arr) {
    double temp1 = p1, temp0 = p0;
    p1 = temp1 * (1 - x) + temp0 * (x);
    p0 = temp0 * (1 - x);
    if (p0 - p1 < 0) {
      cout << setprecision(10) << p1 << endl;
      return 0;
    }
  }
  cout << setprecision(10) << p1 << endl;

  return 0;
}
