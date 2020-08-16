#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[100005][2];
int N, M;
vector<int> adj[100005];
map<int, int> m;

bool check(int idx) {
    for (int i = 0; i < 100005; i++) adj[i].clear();
    m.clear();
    for (int i = 1; i <= idx; i++) {
        int a = arr[i][0], b = arr[i][1];
        adj[b].push_back(a);
        m[a]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (m[i] == 0) q.push(i);
    }
    if (q.size() != 1) return false;
    int ct = 0;
    while (!q.empty()) {
        int u = q.front();
        ct++;
        q.pop();
        for (auto v : adj[u]) {
            m[v]--;
            if (m[v] == 0) q.push(v);
        }
        if (ct != N && q.size() != 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int l = 1, r = M;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (!check(l)) {
        cout << -1 << endl;
    } else {
        cout << l << endl;
    }

    return 0;
}
