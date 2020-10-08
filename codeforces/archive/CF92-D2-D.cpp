#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[100005], ans[100005];
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        v.push_back({arr[i], i});
    }
    memset(ans, -1, sizeof ans);

    sort(v.begin(), v.end());

    int mxIdx = 0, idx = 0;
    while (idx < v.size()) {
        int j = idx;
        int newIdx = mxIdx;
        while (j < v.size() && v[j].first == v[idx].first) {
            ans[v[j].second] = mxIdx <= v[j].second ? -1 : mxIdx - v[j].second - 1;
            newIdx = max(newIdx, v[j].second);
            j++;
        }
        idx = j;
        mxIdx = newIdx;
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
