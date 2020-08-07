#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

map<char, bool> vis;
char arr[25];
string line1;
int T, N;
set<char> adj[25];
int ct = 0;

void solve(int idx) {
    if (idx == N) {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << (i == (N - 1) ? "\n" : " ");
        }
        ct++;
        return;
    }
    for (auto p : vis) {
        if (p.second) continue;
        bool ok = true;
        for (int i = 0; i < idx; i++) {
            if (adj[p.first - 'A'].count(arr[i]) > 0) {
                ok = false;
            }
        }
        if (ok) {
            vis[p.first] = true;
            arr[idx] = p.first;
            solve(idx + 1);
            vis[p.first] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    getline(cin, line1);
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 25; i++) adj[i].clear();
        vis.clear();

        getline(cin, line1);
        istringstream sline(line1);
        char x;
        while (sline >> x) {
            // cout << "char " << x << endl;
            vis[x] = false;
        }
        N = vis.size();
        getline(cin, line1);
        istringstream sline2(line1);
        string y;
        while (sline2 >> y) {
            // cout << "cond " << y[0] << " " << y[2] << endl;
            adj[y[0] - 'A'].insert(y[2]);
        }
        solve(0);
        if (ct == 0) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
