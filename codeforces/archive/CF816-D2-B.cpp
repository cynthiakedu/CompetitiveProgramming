#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 2e5;
int N, K, Q;
ll arr1[mxN + 5], arr2[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> Q;
    for (int i = 0, l, r; i < N; i++) {
        cin >> l >> r;
        arr1[l]++;
        arr1[r + 1]--;
    }
    for (int i = 1; i <= mxN; i++) {
        arr1[i] += arr1[i - 1];
    }
    for (int i = 1; i <= mxN; i++) {
        if (arr1[i] >= K) arr2[i] = 1;
    }
    for (int i = 1; i <= mxN; i++) {
        arr2[i] += arr2[i - 1];
    }
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        cout << arr2[b] - arr2[a - 1] << endl;
    }

    return 0;
}
