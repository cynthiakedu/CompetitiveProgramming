#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int idx = 1;
    while (idx < N && arr[idx] >= arr[idx - 1]) idx++;

    int idx2 = idx;
    int idx3 = idx + 1;
    bool ok = true;
    for (int i = idx2 + 1; i < N; i++) {
        if (arr[i] < arr[i - 1]) ok = false;
    }
    if (idx2 < N && arr[N - 1] > arr[0]) ok = false;
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    cout << N - idx << endl;
    return 0;
}
