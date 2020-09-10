#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, K, T;
int arr[mxN + 5], cum[mxN + 5], must[mxN + 5], extra[mxN + 5];
int s1, s2;
vector<ii> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T >> K;
    for (int i = 1; i <= T; i++) {
        cin >> arr[i];
        cum[i] = arr[i] + cum[i - 1];
    }

    for (int i = 2; i <= T; i++) {
        int a = arr[i - 1], b = arr[i];
        must[i] = max(0, a - b);
        s1 += must[i];
        extra[i] = min(a, b) - 1;
        s2 += extra[i];
    }
    s1 += arr[T];
    if (K < s1) {
        cout << -1 << endl;
        return 0;
    }
    K -= s1;
    if (K > s2) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 2; i <= cum[1] + 1; i++) {
        ans.push_back({1, i});
    }

    for (int i = 2; i <= T; i++) {
        int mn = min(extra[i], K);
        K -= mn;
        int x = mn + must[i];
        int y = arr[i - 1] - x;

        int idx = 0;
        for (int j = cum[i - 1] + 2; j <= cum[i] + 1; j++) {
            int j1 = cum[i - 2] + 2 + idx;
            ans.push_back({j, j1});
            idx = (idx + 1) % y;
        }
    }
    cout << N << endl;
    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
