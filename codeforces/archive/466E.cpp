#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M;
int p[300005], r[300005], b[300005];
int giftNum;
int giftDepth[100005], giftOwner[100005];

int findSet(int i) { return (p[i] == i) ? i : p[i] = findSet(p[i]); }

ii findSet(int i, int bot) {  // return (rep, depth)
  b[i] = bot;
  if (p[i] == i) {
    return ii(i, 0);
  }
  ii f = findSet(p[i], bot);
  p[i] = f.first;
  return ii(f.first, f.second + 1);
}

bool isSameSet(int i, int j) {
  return findSet(i, i).first == findSet(j, j).first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1; i < 300005; i++) p[i] = i;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int type, x, y, num;
    cin >> type;
    if (type == 1) {
      cin >> x >> y;
      p[x] = y;
    } else if (type == 2) {
      cin >> x;
      ii a = findSet(x, x);
      giftDepth[giftNum] = a.second;
      giftOwner[giftNum] = x;
      giftNum++;
    } else {
      cin >> x >> num;
      ii a1 = findSet(x, x);
      ii a2 = findSet(giftOwner[num], giftOwner[num]);
      if (a1.first == a2.first && a1.second < a2.second &&
          b[x] == b[giftOwner[num]]) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
vector<int> p, rank;
