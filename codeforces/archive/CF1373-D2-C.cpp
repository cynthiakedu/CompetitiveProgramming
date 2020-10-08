#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

const int mxN = 1e6;
ll arr[mxN + 5];
int T;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        memset(arr, -1, sizeof arr);
        cin >> s;
        int ct = 0, mx = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '-')
                ct++;
            else
                ct--;
            mx = max(mx, ct);
            if (ct >= 0 && arr[ct] == -1) arr[ct] = i;
        }
        ll mnSoFar = s.size();
        ll ans = s.size();
        for (int i = mx; i >= 1; i--) {
            if (arr[i] != -1) mnSoFar = min(mnSoFar, arr[i]);
            ans += (mnSoFar + 1);
        }
        cout << ans << endl;
    }

    return 0;
}
