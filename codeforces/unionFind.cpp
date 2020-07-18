#include <bits/stdc++.h>
using namespace std;
int p[300005], r[300005], l[300005];

int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }

bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

void unionSet(int i, int j) {
  if (!isSameSet(i, j)) {
    int x = findSet(i), y = findSet(j);
    int newLongPath = max({l[x], l[y], 1 + (l[x] + 1) / 2 + (l[y] + 1) / 2});
    // cout << "unionSet " << x << " " << y << " " << newLongPath << endl;
    if (r[x] > r[y]) {
      p[y] = x;
      l[x] = newLongPath;
    } else {
      p[x] = y;
      l[y] = newLongPath;
      if (r[x] == r[y]) r[y]++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1; i < 300005; i++) p[i] = i;

  return 0;
}
vector<int> p, rank;
