#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, X, arr[100005], mn = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> X;
    X--;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        mn = min(arr[i], mn);
    }
    for (int i = 0; i < N; i++) arr[i] -= mn;
    ll amt = mn * N;
    int idx = X;
    while (arr[idx] != 0) {
        arr[idx] -= 1;
        amt += 1;
        idx = (idx - 1 + N) % N;
    }
    arr[idx] += amt;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << (i == N - 1 ? "\n" : " ");
    }
    return 0;
}
