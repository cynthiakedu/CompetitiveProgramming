#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int arr[105][2];
vector<ii> v;
int ans[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(ans, -1, sizeof ans);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    for (int i = 1; i <= N; i++) {
        v.clear();
        for (int j = 1; j <= N; j++) {
            if (ans[j] == -1) {
                v.push_back({arr[j][0], j});
            }
        }
        sort(v.begin(), v.end());

        int j = 0;
        while (j < v.size() && v[j].first == v[0].first) j++;
        int mnR = arr[v[0].second][1], mnIdx = v[0].second;
        for (int k = 0; k < j; k++) {
            if (arr[v[k].second][1] < mnR) {
                mnR = arr[v[k].second][1];
                mnIdx = v[k].second;
            }
            arr[v[k].second][0]++;
        }
        ans[mnIdx] = arr[mnIdx][0] - 1;
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
