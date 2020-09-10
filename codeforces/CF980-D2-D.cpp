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
    }
    for (int i = 1; i <= N; i++) {
        int ct = 0, freq[5005] = {};
        for (int j = i; j <= N; j++) {
            if (freq[nums[j]] == 0) ct++;
            ans[ct]++;
            freq[nums[j]] = 1;
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
