#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 5000;
ll N, arr[mxN + 5], nums[mxN + 5], counter = 1;
ll ans[mxN + 5];
bool isSquare(ll x) {
    if (x < 0) return false;
    ll y = round(sqrt(x));
    return y * y == x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        bool ok = false;
        for (int j = 1; j < i; j++) {
            if (isSquare(arr[j] * arr[i])) {
                ok = true;
                nums[i] = nums[j];
                break;
            }
        }
        if (!ok) {
            nums[i] = counter++;
        }
        set<int> S;
        for (int j = i; j >= 1; j--) {
            int len = j - i + 1;
            S.insert(nums[j]);
            ans[(int)S.size()]++;
        }
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}