#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K, L;
vector<int> arr;
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> L;

    for (int i = 0, x; i < N * K; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int pos = (int)(upper_bound(arr.begin(), arr.end(), arr[0] + L) - arr.begin());
    if (pos < N) {
        cout << 0 << endl;
        return 0;
    }

    int idx = 0;
    ans += arr[0];
    for (int i = 1; i < N; i++) {
        idx = min(idx + K, pos - (N - i));
        ans += arr[idx];
    }

    cout << ans << endl;

    return 0;
}
