#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int Ca, Cb, N;
vector<string> ansS = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

vector<ii> getNeighbors(ii u) {
    int a = u.first, b = u.second;
    vector<ii> v(6);
    v[0] = ii(Ca, b);
    v[1] = ii(a, Cb);
    v[2] = ii(0, b);
    v[3] = ii(a, 0);
    v[4] = ii(a - min(a, Cb - b), b + min(a, Cb - b));
    v[5] = ii(a + min(b, Ca - a), b - min(b, Ca - a));
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> Ca) && (cin >> Cb) && (cin >> N)) {
        map<ii, pair<ii, int>> p;
        queue<ii> q;
        map<ii, int> dist;

        q.push(ii(0, 0));
        dist[ii(0, 0)] = 0;

        ii ans1;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            // cout << "visit " << u.first << " " << u.second << endl;
            if (u.second == N) {
                ans1 = u;
                break;
            }
            vector<ii> adj = getNeighbors(u);
            for (int i = 0; i < adj.size(); i++) {
                ii v = adj[i];
                if (dist.count(v) == 0) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = {u, i};
                }
            }
        }
        vector<string> ans2 = {"success"};
        while (ans1 != ii(0, 0)) {
            pair<ii, int> up = p[ans1];
            ans2.push_back(ansS[up.second]);
            ans1 = up.first;
        }
        reverse(ans2.begin(), ans2.end());
        for (auto s : ans2) {
            cout << s << endl;
        }
    }

    return 0;
}
