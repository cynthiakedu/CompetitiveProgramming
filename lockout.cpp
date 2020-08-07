#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[100005];
vector<int> cts;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    int idx = 0;
    while (idx < N) {
        int ct = 0;
        int j = idx;
        while (j < N && arr[j] == arr[idx]) {
            ct++;
            j++;
        }
        cts.push_back(ct);
        idx = j;
    }
    for (int i = 0; i < cts.size() - 1; i++) {
        ans = max(ans, 2 * min(cts[i], cts[i + 1]));
    }
    cout << ans << endl;

    return 0;
}
