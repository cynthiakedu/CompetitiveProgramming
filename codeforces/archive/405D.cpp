#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
vector<int> y;
vector<int> p;
int arr[1000005];
int N;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    arr[x] = 1;
  }
  int ct = 0;
  for (int i = 1; i <= MAX / 2; i++) {
    int a = arr[i], b = arr[MAX + 1 - i];
    if (a == 1 && b == 0) {
      y.push_back(MAX + 1 - i);
    } else if (a == 0 && b == 1) {
      y.push_back(i);
    } else if (a == 1 && b == 1) {
      ct++;
    } else {
      p.push_back(i);
    }
  }
  for (auto x : p) {
    if (ct == 0) break;
    y.push_back(x);
    y.push_back(MAX + 1 - x);
    ct--;
  }
  cout << y.size() << endl;
  for (int i = 0; i < y.size(); i++)
    cout << y[i] << (i == y.size() - 1 ? "\n" : " ");
  return 0;
}
