#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, K, arr[1005][105], arr2[1005][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][K ? M - 1 - j : j];
            arr2[i][K ? M - 1 - j : j] = arr[i][K ? M - 1 - j : j];
        }
        sort(arr2[i], arr2[i] + M);
    }
    vector<ii> ans;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int a = arr[j][i], b = arr2[j][i];
            if (a != b) {
                int idx = i + 1;
                while (idx < M && arr[j][idx] != b) idx++;
                ans.push_back({i, idx});
                for (int k = 0; k < N; k++) {
                    if (arr[k][i] > arr[k][idx]) swap(arr[k][i], arr[k][idx]);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) cout << (K ? M - 1 - p.first : p.first) + 1 << " " << (K ? M - 1 - p.second : p.second) + 1 << endl;

    return 0;
}
