#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, T;
int arr[105][1005], cum[105][1005];
map<int, int> m[105];

int solve(int t, int numTrees) {
    if (t == T + 1) return 0;
    if (t == 0) {
        int ret = 0;
        for (int i = 1; i <= arr[0][0]; i++) ret = max(ret, arr[0][i]);
        ret = max(ret, solve(1, 1));
        return ret;
    }
    if (numTrees >= 1000) {
        return cum[t][arr[t][0]] + solve(t + 1, numTrees);
    }
    if (m[t].count(numTrees) > 0) return m[t][numTrees];

    int ret = 0;
    for (int j = 0; j <= min(2 * numTrees, arr[t][0]); j++) {
        ret = max(ret, cum[t][j] + solve(t + 1, 2 * numTrees - j));
    }
    return m[t][numTrees] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    for (int i = 1, t, q; i <= N; i++) {
        cin >> t >> q;
        t = T - t;
        arr[t][arr[t][0] + 1] = q;
        arr[t][0]++;
    }

    for (int i = 0; i <= T; i++) {
        sort(arr[i] + 1, arr[i] + arr[i][0] + 1);
        reverse(arr[i] + 1, arr[i] + arr[i][0] + 1);
        for (int j = 1; j <= arr[i][0]; j++) cum[i][j] = cum[i][j - 1] + arr[i][j];
    }

    cout << solve(0, 0) << endl;

    return 0;
}
