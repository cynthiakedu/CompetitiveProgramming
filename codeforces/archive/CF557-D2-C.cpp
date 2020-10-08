#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, l[100005], d[100005];
vector<ii> v;
int cumCostR[100005];
int cumD[205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> l[i];
    for (int i = 1; i <= N; i++) cin >> d[i];

    for (int i = 1; i <= N; i++) {
        v.push_back({l[i], i});
    }
    v.push_back({0, 0});
    sort(v.begin(), v.end());
    for (int i = N; i >= 1; i--) {
        cumCostR[i] = d[v[i].second];
        cumCostR[i] += cumCostR[i + 1];
    }

    int idx = 1;
    int ans = INT_MAX;
    while (idx <= N) {
        int j = idx;
        while (v[j].first == v[idx].first) {
            j++;
        }
        int totalCost = cumCostR[j];
        int ct = j - idx;
        int need = max(0, idx - 1 - (ct - 1));
        for (int i = 1; i <= 200; i++) {
            int sub = min(cumD[i], need);
            need -= sub;
            totalCost += sub * i;
            if (need == 0) {
                break;
            }
        }

        if (need == 0) {
            ans = min(ans, totalCost);
        }
        for (int i = idx; i < j; i++) {
            cumD[d[v[i].second]]++;
        }
        idx = j;
    }
    cout << ans << endl;

    return 0;
}
