#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
vector<int> arr[2005];
vector<ii> r;  //Right endpoint, index
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int L, R, H;
        cin >> L >> R >> H;
        arr[i] = {H, L, R};
        // r.push_back(ii(arr[i][1], i));
    }
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) {
        int pos = (int)(upper_bound(r.begin(), r.end(), ii(arr[i][1], INT_MAX)) - r.begin());
        if (pos > 0 && r[pos - 1].first >= arr[i][0]) {
            v.push_back(ii(r[pos - 1].first - arr[i][0], arr[r[pos - 1].second][2] - arr[i][2]));
        }
        r.push_back(ii(arr[i][1], i));
    }
    for (auto p : v) {
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = 1; i <= N; i++) {
        }
    }

    return 0;
}
