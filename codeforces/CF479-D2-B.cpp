#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, K, arr[105];
int mn, mx, mni, mxi;
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 0; i < K; i++) {
        mn = INT_MAX, mx = INT_MIN;
        for (int j = 1; j <= N; j++) {
            if (arr[j] < mn) {
                mn = arr[j], mni = j;
            }
            if (arr[j] > mx) {
                mx = arr[j], mxi = j;
            }
        }
        if (mx == mn) break;
        v.push_back(ii(mxi, mni));
        arr[mxi]--, arr[mni]++;
    }
    mn = INT_MAX, mx = INT_MIN;
    for (int j = 1; j <= N; j++) {
        if (arr[j] < mn) {
            mn = arr[j], mni = j;
        }
        if (arr[j] > mx) {
            mx = arr[j], mxi = j;
        }
    }
    cout << mx - mn << " " << v.size() << endl;
    for (auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
