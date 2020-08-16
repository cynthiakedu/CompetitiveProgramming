#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;
vector<int> adj[10005];
ll s = 0;
int mxNode, mxLen = INT_MIN;

void dfs(int u, int d = 0, int p = -1) {
    if (d > mxLen) {
        mxNode = u;
        mxLen = d;
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, d + 1, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 10005; i++) adj[i].clear();
        mxLen = 0;
        s = 0;
        cin >> N;
        for (int i = 1, x, y; i <= N; i++) {
            cin >> x;
            for (int j = 1; j <= x; j++) {
                cin >> y;
                adj[i].push_back(y);
                s++;
            }
        }
        dfs(1);
        mxLen = INT_MIN;
        dfs(mxNode);
        cout << s - mxLen << endl;
    }

    return 0;
}
