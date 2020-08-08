#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, arr[100005], K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    ll amt = K / N;
    if (K % N == 0) {
        cout << arr[amt - 1] << " " << arr[N - 1] << endl;
        return 0;
    }
    ll rem = K % N;
    cout << arr[amt] << " " << arr[rem - 1] << endl;

    return 0;
}
