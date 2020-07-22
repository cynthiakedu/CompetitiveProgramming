#include <bits/stdc++.h>
using namespace std;
int N;
string S;
int arr[200005] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> S;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int mx = -1;
    int dist = INT_MAX;
    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 'R') {
            mx = arr[i];
        } else if (mx != -1) {
            dist = min(dist, arr[i] - mx);
        }
    }
    if (dist == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist / 2 << endl;
    return 0;
}
