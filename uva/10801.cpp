#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K, T[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> N) && (cin >> K)) {
        vector<int> arr[10] = {};
        vector<int> arr2[100] = {};
        vector<ii> adj[800] = {};
        vector<int> dist((N + 2) * 100, -1);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        string line1;
        getline(cin, line1);

        for (int i = 1; i <= N; i++) cin >> T[i];
        getline(cin, line1);

        for (int i = 1; i <= N; i++) {
            getline(cin, line1);
            istringstream sline(line1);
            int x;
            while (sline >> x) {
                arr[i].push_back(x);
                arr2[x].push_back(i);
                if (x == 0) {
                    pq.push({0, 100 * i});
                    dist[100 * i] = 0;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                for (int k = j + 1; k < arr[i].size(); k++) {
                    int a = 100 * i + arr[i][j], b = 100 * i + arr[i][k];
                    int c = abs(a - b) * T[i];
                    adj[a].push_back(ii(b, c));
                    adj[b].push_back(ii(a, c));
                }
            }
        }
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j < arr2[i].size(); j++) {
                for (int k = j + 1; k < arr2[i].size(); k++) {
                    int a = 100 * arr2[i][j] + i, b = 100 * arr2[i][k] + i;
                    adj[a].push_back(ii(b, 60));
                    adj[b].push_back(ii(a, 60));
                }
            }
        }

        int ans = -1;
        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            // cout << "vis " << u << " " << d << endl;
            if (d > dist[u]) continue;
            if (u % 100 == K) {
                ans = dist[u];
                break;
            }

            for (auto v : adj[u]) {
                if (dist[v.first] == -1 || dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        if (ans == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}

// 2 30
// 10 5
// 0 1 3 5 7 9 11 13 15 20 99
// 4 13 15 19 20 25 30

// 1 1
// 2
// 0 2 4 6 8 10