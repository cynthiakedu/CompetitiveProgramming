#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 5000;
bool debug = false;

ll N, arr[mxN + 5], nums[mxN + 5], samples[mxN + 5], counter = 1;
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
        for (int j = 1; j < counter; j++) {
            if (isSquare(arr[i] * samples[j])) {
                nums[i] = j;
                break;
            }
        }
        if (!nums[i]) {
            samples[counter] = arr[i];
            nums[i] = counter++;
        }
        int ct = 0;
        bool freq[505] = {};
        for (int j = i; j >= 1; j--) {
            if (!freq[nums[j]]) ct++;
            ans[ct]++;
            freq[nums[j]] = true;
        }
    }

    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}