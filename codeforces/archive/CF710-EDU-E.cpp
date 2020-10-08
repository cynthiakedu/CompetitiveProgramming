#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
const int mxN = 2e7;
ll dist[mxN + 5];
int N;
ll X, Y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, -1, sizeof dist);
    cin >> N >> X >> Y;

    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, 0});
    dist[0] = 0;

    while (!q.empty()) {
        ii p = q.top();
        q.pop();
        ll u = p.second, d = p.first;

        if (dist[u] < d) continue;
        if (u == N) {
            break;
        }

        if (u > 1) {
            if (dist[u - 1] == -1 || dist[u - 1] > dist[u] + X) {
                dist[u - 1] = dist[u] + X;
                q.push({dist[u - 1], u - 1});
            }
        }
        if (u + 1 < mxN) {
            if (dist[u + 1] == -1 || dist[u + 1] > dist[u] + X) {
                dist[u + 1] = dist[u] + X;
                q.push({dist[u + 1], u + 1});
            }
        }
        if (2 * u < mxN) {
            if (dist[2 * u] == -1 || dist[2 * u] > dist[u] + Y) {
                dist[2 * u] = dist[u] + Y;
                q.push({dist[2 * u], 2 * u});
            }
        }
        dist[u] = -2;
    }
    cout << dist[N] << endl;

    return 0;
}
