#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 3e5;
int lst = INT_MIN;
vector<ii> v;
set<int> S;
int N, K;
int ans = 0, ansl, ansr;
int arr[mxN + 5][2];
int a[mxN + 5][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1, l, r; i <= N; i++) {
        cin >> l >> r;
        l--;
        arr[i][0] = l;
        arr[i][1] = r;
        v.push_back({l, -i});
        v.push_back({r, i});
    }
    sort(v.begin(), v.end());
    int idx = 0;
    int ct = 0;
    while (idx < (int)v.size()) {
        if (lst != INT_MIN) {
            int amt = v[idx].first - lst;
            if (amt > ans && (int)S.size() >= K) {
                ans = amt;
                ansl = lst;
                ansr = v[idx].first;
            }
        }
        int j = idx;
        while (j < (int)v.size() && v[j] == v[idx]) {
            if (v[j].second < 0) {
                S.insert(-v[j].second);
            } else {
                S.erase(v[j].second);
            }
            j++;
        }
        lst = v[idx].first;
        idx = j;
    }
    if (ans == 0) {
        cout << 0 << endl;
        for (int i = 1; i <= K; i++) cout << i << (i == K ? "\n" : " ");
        return 0;
    }
    cout << ans << endl;
    vector<int> ans1;
    for (int i = 1; i <= N; i++) {
        if (arr[i][0] <= ansl && arr[i][1] >= ansr) {
            ans1.push_back(i);
        }
    }
    for (int i = 0; i < K; i++) cout << ans1[i] << (i == K - 1 ? "\n" : " ");

    return 0;
}
