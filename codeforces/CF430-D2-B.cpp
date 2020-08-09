#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K, X, arr[105];
vector<int> v1, v2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> X;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int idx = 0;
    while (idx < N) {
        int j = idx;
        while (j < N && arr[j] == arr[idx]) j++;
        v1.push_back(arr[idx]);
        v2.push_back(j - idx);
        idx = j;
    }
    int ans = 0;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != X) continue;
        if (v2[i] < 2) continue;
        int ct = v2[i];
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < v1.size() && v1[l] == v1[r]) {
            if (v2[l] + v2[r] < 3) break;
            ct += v2[l] + v2[r];
            l--;
            r++;
        }
        ans = max(ans, ct);
    }
    cout << ans << endl;

    return 0;
}
