#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[2][100005];

vector<ii> ans;

void solve(int x) {
    int idx = 0;
    int ct[2] = {};
    while (1) {
        int pos0 = (int)(lower_bound(arr[0] + idx + 1, arr[0] + N + 1, arr[0][idx] + x) - arr[0]);
        int pos1 = (int)(lower_bound(arr[1] + idx + 1, arr[1] + N + 1, arr[1][idx] + x) - arr[1]);
        if (min(pos0, pos1) >= N + 1) break;
        int win = pos0 < pos1 ? 0 : 1;
        ct[win]++;
        idx = min(pos0, pos1);
        if (idx == N) {
            for (int a = 0; a < 2; a++) {
                if (ct[a] > ct[1 - a] && win == a) {
                    ans.push_back({ct[a], x});
                }
            }
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1, x; i <= N; i++) {
        cin >> x;
        arr[x - 1][i]++;
    }
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= N; i++) {
            arr[j][i] += arr[j][i - 1];
        }
    }
    for (int x = 1; x <= N; x++) solve(x);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << " " << p.second << endl;

    return 0;
}
