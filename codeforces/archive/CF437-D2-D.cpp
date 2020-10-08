#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, int>
const int mxN = 10e5;
int N, M;
bool vis[mxN + 5];
ii arr[mxN + 5];
vector<int> adj[mxN + 5];
long double ans = 0;

int p[mxN + 5], r[mxN + 5], num[mxN + 5];

int findSet(int x) {
    return p[x] == x ? x : p[x] = findSet(p[x]);
}

void unionSet(int i, int j) {
    int x = findSet(i), y = findSet(j);
    if (x != y) {
        if (r[x] < r[y]) {
            p[x] = y;
            num[y] += num[x];
        } else {
            p[y] = x;
            num[x] += num[y];
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1, x; i <= N; i++) {
        num[i] = 1;
        p[i] = i;
        cin >> x;
        arr[i] = {x, i};
    }
    sort(arr + 1, arr + N + 1);
    reverse(arr + 1, arr + N + 1);
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        int a = arr[i].first, b = arr[i].second;
        set<int> S;
        ll s1 = 1, s2 = 1;
        for (int v : adj[b]) {
            if (!vis[v]) continue;
            S.insert(findSet(v));
        }
        for (int v : S) {
            s1 += num[v];
            s2 += (ll)num[v] * num[v];
        }
        ans += ((s1 * s1 - s2)) * a;
        for (int v : adj[b]) {
            if (!vis[v]) continue;
            unionSet(v, b);
        }
        vis[b] = true;
    }

    cout << setprecision(16) << ans / ((ll)N * (N - 1)) << endl;

    return 0;
}
