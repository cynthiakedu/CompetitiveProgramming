#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;
ll B;
map<string, vector<int>> m;
vector<string> types;
string Names[1005];
ll P[1005], Q[105];

ll ans1 = -1;

void solve(int idx, ll cost, ll minSoFar) {
    if (cost > B) return;
    if (ans1 != -1 && minSoFar < ans1) return;
    if (idx == types.size()) {
        if (minSoFar > ans1) {
            ans1 = minSoFar;
        }
        return;
    }
    for (auto x : m[types[idx]]) {
        solve(idx + 1, cost + P[x], min(minSoFar, Q[x]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        types.clear();
        m.clear();
        ans1 = -1;
        cin >> N >> B;
        for (int i = 1; i <= N; i++) {
            string type;
            cin >> type;
            cin >> Names[i] >> P[i] >> Q[i];
            m[type].push_back(i);
        }
        for (auto p : m) {
            types.push_back(p.first);
        }
        solve(0, 0, LLONG_MAX);
        cout << ans1 << endl;
    }
    return 0;
}