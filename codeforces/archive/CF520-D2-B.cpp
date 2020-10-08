#include <bits/stdc++.h>
using namespace std;
int N, M;
int dist[20005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < 20005; i++) dist[i] = -1;

    queue<int> q;
    q.push(M);
    dist[M] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u + 1 < 20005 && dist[u + 1] == -1) {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }
        if (u % 2 == 0 && u > 0 && dist[u / 2] == -1) {
            dist[u / 2] = dist[u] + 1;
            q.push(u / 2);
        }
    }
    cout << dist[N] << endl;

    return 0;
}
