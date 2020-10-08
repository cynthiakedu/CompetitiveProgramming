#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

bool debug = false;
int N, K;
ll S, arr[30], fact[20], curr, ans;
vector<int> nums[2];
map<ll, int> res[2][30];

void go(int idx, int num, int id, ll curr = 0) {
    if (curr > S) return;
    if (num > K) return;
    if (idx == nums[id].size()) {
        res[id][num][curr]++;
    } else {
        go(idx + 1, num, id, curr);
        go(idx + 1, num, id, curr + nums[id][idx]);
        if (nums[id][idx] <= 19) {
            go(idx + 1, num + 1, id, curr + fact[nums[id][idx]]);
        }
    }
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

    go(0, 0, 0);
    go(0, 0, 1);

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= i; j++) {
            for (auto p : res[0][j]) {
                if (res[1][i - j].count(S - p.first)) {
                    ans += p.second * res[1][i - j][S - p.first];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
