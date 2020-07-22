#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, Q, oriMax = 0, arr[100005];
set<ii> S;  // endpoint position, id (neg if left endpoint)

vector<ii> queries;  // length, id
int L[5005], R[5005];
double P[5005];

double globalCumProb[5005];
double indivCumProb[5005][5005];
double ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    arr[i] = x;
    S.insert(ii(i, -i));
    S.insert(ii(i, i));
    oriMax = max(x, oriMax);
  }

  for (int i = 0; i < Q; i++) {
    int l, r;
    double p;
    cin >> l >> r >> p;
    L[i] = l;
    R[i] = r;
    P[i] = p;
    queries.push_back(ii(r - l + 1, i));
  }
  sort(queries.begin(), queries.end());

  for (int j = 1; j <= Q + 1; j++) globalCumProb[j] = 1;

  for (int i = 0; i < Q; i++) {
    int qid = queries[i].second;
    set<ii>::iterator itLeft = S.upper_bound(ii(L[qid], INT_MIN));
    set<ii>::iterator itRight = S.upper_bound(ii(R[qid], INT_MAX));
    cout << "Inserting query " << qid << " with l/r = " << L[qid] << " "
         << R[qid] << endl;

    double containingCumProb[5005];
    double containingExactProb[5005];
    double otherCumProb[5005];
    int containingMax = -1;

    while (itLeft != itRight) {
      ii p1 = *itLeft;
      itLeft++;
      ii p2 = *itLeft;
      itLeft++;
      cout << "looking at... " << p1.first << " " << p2.first << " "
           << p2.second << endl;
      S.erase(prev(itLeft));
      S.erase(prev(itLeft));
      if (p2.second < N) {
        containingMax = max(containingMax, arr[p2.second]);
      } else {
        for (int j = 0; j <= Q + 1; j++) {
          containingCumProb[j] =
              containingCumProb[j] * indivCumProb[p2.second - N][j];
        }
      }
    }

    if (containingMax > 0) {
      for (int j = 0; j < containingMax; j++) {
        containingCumProb[j] = 0;
      }
    }
    containingExactProb[0] = containingCumProb[0];
    for (int j = 1; j <= Q + 1; j++) {
      containingExactProb[j] = containingCumProb[j] - containingCumProb[j - 1];
    }

    cout << "containingCumProb" << endl;
    for (int j = 0; j <= Q + 1; j++) {
      cout << containingCumProb[j] << " ";
    }
    cout << endl;
    cout << "containingExactProb" << endl;
    for (int j = 0; j <= Q + 1; j++) {
      cout << containingExactProb[j] << " ";
    }
    cout << endl;
    cout << "otherCumProb" << endl;
    for (int j = 0; j <= Q + 1; j++) {
      cout << otherCumProb[j] << " ";
    }
    cout << endl;

    double probHasMax = 0;
    for (int j = 1; j <= Q + 1; j++) {
      probHasMax += containingExactProb[j] * otherCumProb[j];
    }

    ans += probHasMax;

    for (int j = 0; j <= Q + 1; j++) {
      globalCumProb[j] *= containingCumProb[j];
    }
    S.insert(ii(L[qid], -(qid + N)));
    S.insert(ii(R[qid], (qid + N)));
  }

  cout << ans << endl;

  return 0;
}
