#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;
const int mxN = 2e5 + 5;
int a[mxN], b[mxN];
vector<ii> al[mxN];
ll ans = 0;

ll dfs(int x) {
    ll ret = a[x];
    for (int i = 0; i < al[x].size(); i++) {
        ll t = dfs(al[x][i].first);
        if (t >= 0) {
            al[x][i].second = 1;
            ret += t;
        }
    }
    ans += ret;
    return ret;
}
vector<int> ansV;
void dfs2(int x) {
    for (int i = 0; i < al[x].size(); i++) {
        if (al[x][i].second == 1) {
            dfs2(al[x][i].first);
        }
    }
    ansV.push_back(x);
    for (int i = 0; i < al[x].size(); i++) {
        if (al[x][i].second == 0) {
            dfs2(al[x][i].first);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];

    queue<int> q;
    vector<int> v;

    for (int i = 1; i <= N; i++) {
        if (b[i] == -1) {
            v.push_back(i);
        } else {
            al[b[i]].push_back({i, 0});
        }
    }
    for (auto x : v) {
        dfs(x);
    }
    for (auto x : v) {
        dfs2(x);
    }

    cout << ans << endl;
    for (int i = 0; i < ansV.size(); i++) cout << ansV[i] << (i == (ansV.size() - 1) ? "\n" : " ");
    return 0;
}
