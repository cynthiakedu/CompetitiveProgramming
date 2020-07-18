#include <bits/stdc++.h>
using namespace std;
typedef pair<int, double> ii;
#define T (1 << 17)
int N, M;
double s[100005], m[100005], rate[100005];
set<ii> S;

vector<vector<double>> tree[2 * T];
double tree2[2 * T];

vector<vector<double>> merge(vector<vector<double>> p,
                             vector<vector<double>> q) {
  vector<vector<double>> pq(p.size() + q.size());
  merge(p.begin(), p.end(), q.begin(), q.end(), pq.begin());

  for (int i = 1; i < pq.size(); i++) {
    pq[i][2] = pq[i - 1][2] + m[(int)pq[i][1]];
    pq[i][3] = pq[i - 1][3] + rate[(int)pq[i][1]];
  }
  return pq;
}

double f(int l, int r, double t, int id = 1, int low = 0, int high = T) {
  if (l <= low && r >= high) {
    int pos = (int)(upper_bound(tree[id].begin(), tree[id].end(),
                                vector<double>{t, -1, -1}) -
                    tree[id].begin());
    return t * tree2[id] -
           (pos == 0 ? 0 : t * tree[id][pos - 1][3] - tree[id][pos - 1][2]);
  };
  int mid = (low + high) / 2;
  if (r <= mid) return f(l, r, t, id * 2, low, mid);
  if (l >= mid) return f(l, r, t, id * 2 + 1, mid, high);
  return f(l, r, t, id * 2, low, mid) + f(l, r, t, id * 2 + 1, mid, high);
}

double process(int l, int r, double t) {
  set<ii>::iterator it = S.lower_bound(ii(l, LLONG_MIN));
  ii p = *it;
  if (p.second > 0) {
    S.insert(ii(l - 1, p.second));
    S.insert(ii(l, -p.second));
    it--;
  }
  double ret = 0;
  while (it != S.end()) {
    ii p1 = *it;
    it++;
    ii p2 = *it;

    if (p1.first > r) {
      break;
    } else if (p2.first <= r) {
      if (p2.second == INT_MAX) {
        ret += min(s[p1.first] + t * rate[p1.first], m[p1.first]);
      } else {
        ret += f(p1.first, p2.first + 1, t - p2.second);
      }
      it++;
      S.erase(prev(it));
      S.erase(prev(it));
    } else {
      ret += f(p1.first, r + 1, t - p2.second);
      S.erase(prev(it));
      S.insert(ii(r + 1, p1.second));
      break;
    }
  }
  S.insert(ii(l, -t));
  S.insert(ii(r, t));
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> s[i] >> m[i] >> rate[i];
  }

  // Prepare trees
  for (int i = 1; i <= N; i++) {
    vector<double> x =
        vector<double>{rate[i] != 0 ? (double)m[i] / rate[i] : DBL_MAX,
                       (double)i, m[i], rate[i]};
    vector<vector<double>> v =
        rate[i] != 0 ? vector<vector<double>>{x} : vector<vector<double>>{};
    tree[T + i] = v;
    tree2[T + i] = rate[i];
    S.insert(ii(i, -INT_MAX));
    S.insert(ii(i, INT_MAX));
  }
  for (int i = T - 1; i >= 1; i--) {
    tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    tree2[i] = tree2[2 * i] + tree2[2 * i + 1];
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int l, r;
    double t;
    cin >> t >> l >> r;
    cout << (long long)process(l, r, t) << "\n";
  }

  return 0;
}

// 3
// 1 10 1
// 0 12 2
// 0 20 1
// 1
// 14 1 3

// 3
// 1 10 1
// 0 12 5
// 0 20 1
// 1
// 2 1 3

// 3
// 1 10 1
// 0 12 5
// 0 20 1
// 1
// 3 1 3

// 3
// 0 10 2
// 3 10 4
// 1 7 3
// 3
// 5 1 2
// 6 2 3
// 9 1 3
// ret: 20, 11, 25
