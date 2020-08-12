#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, K;
vector<int> arr[100005];
vector<ii> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        arr[x].push_back(i);
    }
    if (arr[0].size() != 1 || arr[1].size() > K) {
        cout << -1 << endl;
        return 0;
    }
    for (auto x : arr[1]) {
        ans.push_back({arr[0][0], x});
    }

    for (int i = 1; i < N; i++) {
        if (arr[i].size() == 0 && arr[i + 1].size() > 0) {
            cout << -1 << endl;
            return 0;
        }
        if (arr[i + 1].size() > (ll)(K - 1) * arr[i].size()) {
            cout << -1 << endl;
            return 0;
        }
        int idx = 0, ct = 0;
        for (int x : arr[i + 1]) {
            ans.push_back({arr[i][idx], x});
            ct++;
            if (ct == K - 1) {
                idx++;
                ct = 0;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << " " << p.second << endl;

    return 0;
}
