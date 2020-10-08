#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, D, K;
vector<ii> ans;
int num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> D >> K;
    if (N < D + 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (K == 1) {
        if (N == 1) {
            cout << "YES" << endl;
            return 0;
        }
        if (N == 2) {
            if (D == 1) {
                cout << "YES" << endl;
                cout << 1 << " " << 2 << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }

    queue<int> q;
    vector<int> dist(N + 1, -1);
    for (int i = 1; i <= D; i++) {
        ans.push_back({i, i + 1});
    }

    num = D + 1;
    for (int i = 2; i <= D; i++) {
        q.push(i);
        dist[i] = max(i - 1, D + 1 - i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] == D) continue;
        int ct = u <= D + 1 ? K - 2 : K - 1;

        while (num < N && ct > 0) {
            dist[++num] = dist[u] + 1;
            q.push(num);
            ct--;
            ans.push_back({u, num});
        }
    }
    if (num < N) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (auto x : ans) cout << x.first << " " << x.second << "\n";

    return 0;
}
