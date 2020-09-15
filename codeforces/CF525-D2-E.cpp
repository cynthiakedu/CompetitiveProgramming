#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, int>
bool debug = false;
int N, K;
ll S, arr[30], fact[20], curr, ans;
vector<int> nums[2];
map<ii, int> v[2];

void solve(int idx, int num, int id) {
    if (curr > S) return;
    if (idx == nums[id].size()) {
        v[id][{curr, num}]++;
        return;
    }
    solve(idx + 1, num, id);

    curr += nums[id][idx];
    solve(idx + 1, num, id);
    curr -= nums[id][idx];

    if (num == 0) return;
    if (nums[id][idx] >= 19) return;

    curr += fact[nums[id][idx]];
    solve(idx + 1, num - 1, id);
    curr -= fact[nums[id][idx]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (ll i = 1; i <= 19; i++) fact[i] = fact[i - 1] * i;

    cin >> N >> K >> S;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N / 2; i++) nums[0].push_back(arr[i]);
    for (int i = N / 2 + 1; i <= N; i++) nums[1].push_back(arr[i]);

    solve(0, K, 0);
    solve(0, K, 1);
    for (auto p : v[1]) {
        if (debug) cout << p.first.first << " " << p.first.second << " " << p.second << endl;
        for (int i = 0; i <= p.first.second; i++) {
            if (v[0].count({S - p.first.first, K - i}) > 0) {
                ans += v[0][{S - p.first.first, K - i}] * p.second;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
