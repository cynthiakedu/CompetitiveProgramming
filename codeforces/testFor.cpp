#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v = {1};
  for (int idx = 0; idx < (int)v.size() - 1; idx += 2) {
    cout << "idx " << idx << endl;
  }
  return 0;
}
