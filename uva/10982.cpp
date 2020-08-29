#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N, M;
vector<int> adj[105];
int arr[105];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "Case #" << t + 1 << ": ";
        memset(arr, 0, sizeof arr);
        for (int i = 0; i < 105; i++) adj[i].clear();
        ans.clear();

        cin >> N >> M;
        for (int i = 0, u, v; i < M; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= N; i++) {
            int a = 0, b = 0;
            for (auto v : adj[i]) {
                if (arr[v] == 1)
                    a++;
                else if (arr[v] == 2)
                    b++;
            }
            if (a > b) {
                arr[i] = 2;
                ans.push_back(i);
            } else {
                arr[i] = 1;
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }

    return 0;
}
