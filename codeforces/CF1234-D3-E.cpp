#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, M;
int arr[mxN + 5];
vector<int> adj[mxN + 5];
vector<ll> cum[mxN + 5];
ll s = 0;
vector<ll> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) cin >> arr[i];
    for (int i = 1; i < M; i++) {
        int a = arr[i], b = arr[i + 1];
        adj[a].push_back(b);
        adj[b].push_back(a);
        s += abs(a - b);
    }
    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
        if (adj[i].size() == 0) continue;
        cum[i].resize(adj[i].size() + 1);
        for (int j = 0; j < adj[i].size(); j++) {
            cum[i][j + 1] = adj[i][j];
            cum[i][j + 1] += cum[i][j];
        }
    }
    ans.push_back(s);
    for (int i = 2; i <= N; i++) {
        int pos1 = (int)(lower_bound(adj[i - 1].begin(), adj[i - 1].end(), i + 1) - adj[i - 1].begin());
        int pos2 = (int)(upper_bound(adj[i - 1].begin(), adj[i - 1].end(), i - 2) - adj[i - 1].begin());
        s -= (ll)(adj[i - 1].size() - pos1) * (i - 1);
        if (pos2 >= 1) s += (ll)(pos2) * (i - 1) - 2LL * cum[i - 1][pos2];
        int pos3 = (int)(lower_bound(adj[i].begin(), adj[i].end(), i + 1) - adj[i].begin());
        int pos4 = (int)(upper_bound(adj[i].begin(), adj[i].end(), i - 2) - adj[i].begin());
        s += (ll)(adj[i].size() - pos3) * (i - 1);
        if (pos4 >= 1) s += 2LL * cum[i][pos4] - (ll)pos4 * (i - 1);
        ans.push_back(s);
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");

    return 0;
}
