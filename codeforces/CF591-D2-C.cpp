#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[500005];
vector<int> v1, v2;
int ans1 = 0;
vector<int> ans2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    arr[0] = arr[1];
    arr[N + 1] = arr[N];

    int idx = 0;
    while (idx <= N + 1) {
        int j = idx;
        while (j <= N + 1 && arr[j] == arr[idx]) j++;
        v1.push_back(arr[idx]);
        v2.push_back(j - idx);
        idx = j;
    }

    idx = 0;
    while (idx < v1.size()) {
        if (v2[idx] > 1) {
            for (int i = 0; i < v2[idx]; i++) {
                ans2.push_back(v1[idx]);
            }
            idx++;
            continue;
        }
        int j = idx;
        while (j < v1.size() && v2[j] == 1) j++;
        int amt = j - idx;
        if (amt % 2 == 0) {
            ans1 = max(ans1, amt / 2);
            for (int i = 0; i < amt / 2; i++) ans2.push_back(v1[idx - 1]);
            for (int i = 0; i < amt / 2; i++) ans2.push_back(v1[j]);
        } else {
            ans1 = max(ans1, (amt + 1) / 2);
            for (int i = 0; i < amt; i++) ans2.push_back(v1[idx - 1]);
        }

        idx = j;
    }

    cout << ans1 << endl;
    for (int i = 1; i < ans2.size() - 1; i++) cout << ans2[i] << (i == ans2.size() - 2 ? "\n" : " ");

    return 0;
}
