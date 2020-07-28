#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M, x[300005], ans[300005];

vector<ii> V;
set<ii> S;
int idxV = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1, l, r; i <= M; i++) {
        cin >> l >> r >> x[i];
        V.push_back(ii(l, -i));
        V.push_back(ii(r, i));
    }
    for (int i = 1; i <= N; i++) {
        while (idxV < V.size() && V[idxV].first == i && V[idxV].second < 0) {
            S.insert(V[idxV]);
            idxV++;
        }
        vector<ii> v;
        while (S.size()) {
            ii p = *S.begin();
            S.erase(p);
            v.push_back(p);
            if (x[p.second] != i) {
                ans[i] = p.second;
                break;
            }
        }
        for (auto p : v) S.insert(p);

        while (idxV < V.size() && V[idxV].first == i && V[idxV].second > 0) {
            S.erase(ii(V[idxV].first, -V[idxV].second));
            idxV++;
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
